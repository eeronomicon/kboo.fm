<?php
/**
 * Class file of SpinPapiData.
 *
 * PHP version 5.3
 *
 * Copyright (c) 2014 Spinitron, LLC. <eva@spinitron.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with or
 * without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO
 * THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * @category    SpinPapi
 * @author      Tom Worster <tom@spinitron.com>
 * @copyright   2014 Spinitron, LLC
 * @license     ISC http://opensource.org/licenses/ISC
 * @link        https://bitbucket.org/Spinitron/spinpapi-php-client
 */

class SpinPapiException extends Exception
{
}

/**
 * Class SpinPapiData Provides simple access to SpinPapi data for use in web apps.
 */
class SpinPapiData
{
    /**
     * @var string What to do on SpinPapi error response. Set to:
     *   - 'notice' to trigger a PHP E_USER_NOTICE
     *   - 'throw' to throw a SpinPapiException
     *   - 'log:filepath' to log a message to the file at filepath
     */
    public $onError;

    /**
     * @var string A Spinitron station ID
     */
    public $station;

    /**
     * @var string A SpinPapi authentication user ID
     */
    public $userId;

    /**
     * @var string SpinPapi authentication secret
     */
    public $secret;

    /**
     * @var string|array Cache directory path or array of memcache servers
     */
    public $cache;

    /**
     * @var SpinPapiClient
     */
    private $client;

    /**
     * Construct a new SpinPapiData object.
     *
     * The SpinPapiClient object is not instantiated until it is used.
     *
     * @param string|array $config A file path to a config file or a configuration array.
     *
     * @throws SpinPapiException on configuration error.
     */
    public function __construct($config)
    {
        if (is_string($config)) {
            if (!is_file($config) || !is_readable($config)) {
                throw new SpinPapiException('Invalid config file: ' . $config);
            }

            /** @noinspection PhpIncludeInspection */
            $config = include($config);
        }
        foreach ($config as $key => $value) {
            if (!property_exists($this, $key)) {
                throw new SpinPapiException('Invalid config parameter: ' . $key);
            }
            $this->$key = $value;
        }
    }

    /**
     * Returns the local SpinPapiClient object.
     *
     * Instantiates the local SpinPapiClient object if it does not exist.
     *
     * @return SpinPapiClient
     * @throws SpinPapiException on configuration error.
     */
    public function getClient()
    {
        if ($this->client === null) {
            $this->client =
                new SpinPapiClient($this->userId, $this->secret, $this->station, $this->onError === 'notice');

            if ($this->cache) {
                if (is_string($this->cache)) {
                    if (!is_dir($this->cache) || !is_writable($this->cache)) {
                        throw new SpinPapiException('Cache dir not found or not writable: ' . $this->cache);
                    }
                    $this->client->fcInit($this->cache);
                } elseif (is_array($this->cache)) {
                    $this->client->mcInit($this->cache);
                } else {
                    throw new SpinPapiException('Invalid cache config.');
                }
            } else {
                throw new SpinPapiException('Missing cache config.');
            }
        }

        return $this->client;
    }

    /**
     * Runs the SpinPapi query and checks the response.
     *
     * @param $query
     *
     * @return bool|array False on SpinPapi error response.
     * @throws SpinPapiException on error response if $this->onError is 'throw'
     */
    protected function runQuery($query)
    {
        $response = $this->getClient()->query($query);

        if ($response['success'] === true) {
            return $response['results'];
        }

        $message = 'SpinPapi error respose: ' . implode('. ', $response['errors']);
        if ($this->onError === 'notice') {
            trigger_error($message, E_USER_NOTICE);
        } elseif ($this->onError === 'throw') {
            throw new SpinPapiException($message);
        } elseif (strpos($this->onError, 'log:') === 0) {
            file_put_contents(
                substr($this->onError, 4),
                gmdate('Y-m-d\TH:i:s\Z ') . $message . "\n",
                FILE_APPEND
            );
        }

        return false;
    }

    /**
     * Wrapper for SpinPapi getSong method.
     *
     * @see SpinPapi API Specification https://bitbucket.org/spinitron/documentation
     *
     * @return array
     */
    public function song()
    {
        return $this->runQuery(
            array(
                'method' => 'getSong',
            )
        );
    }

    /**
     * Wrapper for SpinPapi getSongs method.
     *
     * @see SpinPapi API Specification https://bitbucket.org/spinitron/documentation
     *
     * @param int $num
     *
     * @return array
     */
    public function songs($num = 1)
    {
        return $this->runQuery(
            array(
                'method' => 'getSongs',
                'Num' => $num,
            )
        );
    }

    /**
     * Wrapper for SpinPapi getPlaylistInfo method.
     *
     * @see SpinPapi API Specification https://bitbucket.org/spinitron/documentation
     *
     * @param null $playlistId
     *
     * @return array
     */
    public function playlistInfo($playlistId = null)
    {
        return $this->runQuery(
            array(
                'method' => 'getPlaylistInfo',
                'PlaylistID' => $playlistId,
            )
        );
    }

    /**
     * Wrapper for SpinPapi getShowInfo method.
     *
     * @see SpinPapi API Specification https://bitbucket.org/spinitron/documentation
     *
     * @param null $showId
     *
     * @return array
     */
    public function showInfo($showId = null)
    {
        return $this->runQuery(
            array(
                'method' => 'getShowInfo',
                'ShowID' => $showId,
            )
        );
    }

    /**
     * Wrapper for SpinPapi getRegularShowsInfo method.
     *
     * @see SpinPapi API Specification https://bitbucket.org/spinitron/documentation
     *
     * @param string $when
     * @param null $startHour
     *
     * @return array
     */
    public function regularShowsInfo($when = 'now', $startHour = null)
    {
        return $this->runQuery(
            array(
                'method' => 'getRegularShowsInfo',
                'When' => $when,
                'StartHour' => $startHour,
            )
        );
    }
}
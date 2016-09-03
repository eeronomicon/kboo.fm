<?xml version="1.0" encoding="utf-8"?>
<rss version="2.0" xmlns:itunes="http://www.itunes.com/dtds/podcast-1.0.dtd" xmlns:atom="http://www.w3.org/2005/Atom">

  <?php $station_name = "KBOO Community Radio"; $station_email = "podcast@kboo.org";?>

  <channel>
    <title><?php print $program['title']; ?></title>
    <atom:link href="<?php print $program['podcast_url']; ?>" rel="self" type="application/rss+xml"/>
    <link><?php print $program['url']; ?></link>
    <language>en-us</language>
    <copyright>&#x2117; &amp; &#xA9; <?php print date('Y') . " " . $station_name; ?></copyright>
    <itunes:owner>
      <itunes:name><?php print $station_name; ?></itunes:name>
    </itunes:owner>
    <itunes:category text="Public Radio">
      <itunes:category text="Public Radio" />
    </itunes:category>
    <itunes:explicit><?php print $program['explicit']; ?></itunes:explicit>
    <itunes:image>
      <url><?php print $program['image']; ?></url>
      <title><?php print $program['title']; ?></title>
      <link><?php print $program['url']; ?></link>
    </itunes:image>

    <?php foreach ($items as $item): ?>
      <item>
        <title><?php print $item['title']; ?></title>

        <link><?php print $item['url']; ?></link>

        <pubDate><?php print $item['published_date']; ?></pubDate>

        <itunes:author><?php print $station_name ?></itunes:author>

        <itunes:summary><?php print $item['summary']; ?></itunes:summary>

        <itunes:image href="<?php print $item['image']; ?>" />

        <enclosure url="<?php print $item['audio_file']; ?>" length="<?php print $item['duration']; ?>" type="audio/mpeg"/>

        <guid><?php print $item['url']; ?></guid>

        <itunes:keywords></itunes:keywords>
      </item>
    <?php endforeach; ?>
  </channel>
</rss>

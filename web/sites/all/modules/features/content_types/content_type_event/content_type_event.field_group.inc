<?php
/**
 * @file
 * content_type_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_event_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_bottom|node|event|form';
  $field_group->group_name = 'group_content_bottom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content below media',
    'weight' => '4',
    'children' => array(
      0 => 'field_body_below_media',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content-bottom field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content_bottom|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|event|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_audio_files',
      2 => 'field_event_date',
      3 => 'field_event_type',
      4 => 'field_genres',
      5 => 'field_lead_image',
      6 => 'field_location',
      7 => 'field_more_images',
      8 => 'field_parent_section',
      9 => 'field_produced_for',
      10 => 'field_short_description',
      11 => 'field_topic_tags',
      12 => 'field_venue',
      13 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_developer_info|node|event|form';
  $field_group->group_name = 'group_developer_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Developer info',
    'weight' => '9',
    'children' => array(
      0 => 'field_d6_nid',
      1 => 'field_published_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-developer-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_developer_info|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|event|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '3',
    'children' => array(
      0 => 'field_files',
      1 => 'field_links',
      2 => 'field_video_files',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_media|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_info|node|event|form';
  $field_group->group_name = 'group_profile_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile info',
    'weight' => '5',
    'children' => array(
      0 => 'field_authored_by',
      1 => 'field_hosted_by',
      2 => 'field_sponsored_by',
      3 => 'field_produced_by',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_profile_info|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|event|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related info',
    'weight' => '6',
    'children' => array(
      0 => 'field_related_info_content',
      1 => 'field_related_organizations',
      2 => 'field_related_programs',
      3 => 'field_related_show_hosts',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Related info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-related field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_related|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser_info|node|event|form';
  $field_group->group_name = 'group_teaser_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser info',
    'weight' => '10',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-teaser-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_teaser_info|node|event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Content below media');
  t('Developer info');
  t('Media');
  t('Profile info');
  t('Related info');
  t('Teaser info');

  return $field_groups;
}

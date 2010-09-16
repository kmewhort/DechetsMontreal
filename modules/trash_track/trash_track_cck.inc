<?php
/**
 *   Drupal Module for retrieving & parsing trash and recycling schedules
 *   for Montreal (as used by www.dechetsmontreal.ca).
 *
 *   © 2010 Kent Mewhort. This module is distributed under the terms of the
 *   GNU General Public License Version 3 <http://www.gnu.org/licenses/gpl.html>.
 *
 **/

// CCK types (trash_schedule and trash_collection)
function _trash_track_collection_export() {

$content['type']  = array (
  'name' => 'Trash Collection',
  'type' => 'trash_collection',
  'description' => 'Collection dates and collection information for a particular type of waste (household waste, recycling, etc).',
  'title_label' => 'Postal Code',
  'body_label' => 'Collection Info',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => false,
    'promote' => false,
    'sticky' => false,
    'revision' => false,
  ),
  'language_content_type' => 0,
  'old_type' => 'trash_collection',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'comment' => '0',
  'comment_default_mode' => '4',
  'comment_default_order' => '1',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '1',
  'comment_preview' => '1',
  'comment_form_location' => '0',
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Collection Type',
    'field_name' => 'field_collection_type',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '-4',
    'rows' => 5,
    'size' => '60',
    'description' => 'Type of trash collection ("garbage", "recycling", "large", or "green")',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_collection_type][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'weight' => '-4',
      'parent' => '',
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 1,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'Collection Type (Nice)',
    'field_name' => 'field_collection_type_nice',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '-3',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_collection_type_nice][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_collection_type_nice' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_collection_type_nice][0][value',
        ),
      ),
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'weight' => '-3',
      'parent' => '',
      'label' => 
      array (
        'format' => 'hidden',
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  2 => 
  array (
    'label' => 'Collection Dates',
    'field_name' => 'field_collection_dates',
    'type' => 'date',
    'widget_type' => 'date_popup_repeat',
    'change' => 'Change basic information',
    'weight' => '-2',
    'default_value' => 'blank',
    'default_value2' => 'same',
    'default_value_code' => '',
    'default_value_code2' => '',
    'input_format' => 'm/d/Y - H:i:s',
    'input_format_custom' => '',
    'year_range' => '-3:+3',
    'increment' => '1',
    'advanced' => 
    array (
      'label_position' => 'above',
      'text_parts' => 
      array (
        'year' => 0,
        'month' => 0,
        'day' => 0,
        'hour' => 0,
        'minute' => 0,
        'second' => 0,
      ),
    ),
    'label_position' => 'above',
    'text_parts' => 
    array (
    ),
    'description' => '',
    'group' => false,
    'required' => 0,
    'multiple' => 1,
    'repeat' => 1,
    'todate' => '',
    'granularity' => 
    array (
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'default_format' => 'medium',
    'tz_handling' => 'none',
    'timezone_db' => 'America/Montreal',
    'repeat_collapsed' => '0',
    'op' => 'Save field settings',
    'module' => 'date',
    'widget_module' => 'date',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'varchar',
        'length' => 20,
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
      'rrule' => 
      array (
        'type' => 'text',
        'not null' => false,
        'sortable' => false,
        'views' => false,
      ),
    ),
    'display_settings' => 
    array (
      'weight' => '-2',
      'parent' => '',
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 1,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'body_field' => '0',
  'revision_information' => '1',
  'author' => '2',
  'options' => '3',
  'comment_settings' => '4',
  'menu' => '-1',
  'path' => '5',
);

return $content;
}

function _trash_track_schedule_export() {

$content['type']  = array (
  'name' => 'Trash Schedule',
  'type' => 'trash_schedule',
  'description' => 'A trash schedule for a particular postal code.  Each trash schedule contains one or more trash collections.',
  'title_label' => 'Postal code',
  'body_label' => '',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => false,
    'promote' => false,
    'sticky' => false,
    'revision' => false,
  ),
  'language_content_type' => 0,
  'old_type' => 'trash_schedule',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'comment' => '0',
  'comment_default_mode' => '4',
  'comment_default_order' => '1',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '1',
  'comment_preview' => '1',
  'comment_form_location' => '0',
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Raw Schedule Data',
    'field_name' => 'field_raw_data',
    'type' => 'filefield',
    'widget_type' => 'filefield_widget',
    'change' => 'Change basic information',
    'weight' => '-4',
    'file_extensions' => 'htm html',
    'progress_indicator' => 'bar',
    'file_path' => '',
    'max_filesize_per_file' => '',
    'max_filesize_per_node' => '',
    'description' => '',
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'op' => 'Save field settings',
    'module' => 'filefield',
    'widget_module' => 'filefield',
    'columns' => 
    array (
      'fid' => 
      array (
        'type' => 'int',
        'not null' => false,
        'views' => true,
      ),
      'list' => 
      array (
        'type' => 'int',
        'size' => 'tiny',
        'not null' => false,
        'views' => true,
      ),
      'data' => 
      array (
        'type' => 'text',
        'serialize' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'Collections',
    'field_name' => 'field_collection_refs',
    'type' => 'nodereference',
    'widget_type' => 'nodereference_autocomplete',
    'change' => 'Change basic information',
    'weight' => '-3',
    'autocomplete_match' => 'contains',
    'size' => '60',
    'description' => 'Collections for this schedule (one for garbage, one for recycling, etc.).',
    'default_value' => 
    array (
      0 => 
      array (
        'nid' => NULL,
        '_error_element' => 'default_value_widget][field_collection_refs][0][nid][nid',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_collection_refs' => 
      array (
        0 => 
        array (
          'nid' => 
          array (
            'nid' => '',
            '_error_element' => 'default_value_widget][field_collection_refs][0][nid][nid',
          ),
          '_error_element' => 'default_value_widget][field_collection_refs][0][nid][nid',
        ),
      ),
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '1',
    'referenceable_types' => 
    array (
      'trash_collection' => 'trash_collection',
      'page' => 0,
      'story' => 0,
      'trash_schedule' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'op' => 'Save field settings',
    'module' => 'nodereference',
    'widget_module' => 'nodereference',
    'columns' => 
    array (
      'nid' => 
      array (
        'type' => 'int',
        'unsigned' => true,
        'not null' => false,
        'index' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'revision_information' => '0',
  'author' => '-1',
  'options' => '1',
  'comment_settings' => '3',
  'menu' => '-2',
  'path' => '2',
);


return $content;
}

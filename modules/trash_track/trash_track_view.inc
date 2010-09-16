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
function _trash_track_view_export() {

$view = new view;
$view->name = 'trash_calendar';
$view->description = '';
$view->tag = 'Trash Calendar';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'field_collection_dates_value' => array(
    'label' => 'Collection Dates',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'group' => 0,
    ),
    'repeat' => array(
      'show_repeat_rule' => 'show',
    ),
    'fromto' => array(
      'fromto' => 'both',
    ),
    'exclude' => 1,
    'id' => 'field_collection_dates_value',
    'table' => 'node_data_field_collection_dates',
    'field' => 'field_collection_dates_value',
    'relationship' => 'none',
  ),
  'field_collection_type_value' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 1,
      'text' => '<div class="trash_track_[field_collection_type_value]"></div><div class="trash_track_date_details">details</div>',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 1,
    'label_type' => 'none',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_collection_type_value',
    'table' => 'node_data_field_collection_type',
    'field' => 'field_collection_type_value',
    'relationship' => 'none',
  ),
  'field_collection_type_nice_value' => array(
    'label' => 'Collection Type (Nice)',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 1,
    'id' => 'field_collection_type_nice_value',
    'table' => 'node_data_field_collection_type_nice',
    'field' => 'field_collection_type_nice_value',
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => 'Title',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
  'body' => array(
    'label' => 'Body',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 1,
    'id' => 'body',
    'table' => 'node_revisions',
    'field' => 'body',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'title' => array(
    'default_action' => 'empty',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'glossary' => 0,
    'limit' => '0',
    'case' => 'none',
    'path_case' => 'none',
    'transform_dash' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => 'lookup',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'page' => 0,
      'story' => 0,
      'trash_collection' => 0,
      'trash_schedule' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
  'date_argument' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'date',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'date_fields' => array(
      'node_data_field_collection_dates.field_collection_dates_value' => 'node_data_field_collection_dates.field_collection_dates_value',
    ),
    'year_range' => '-1:+1',
    'date_method' => 'OR',
    'granularity' => 'month',
    'id' => 'date_argument',
    'table' => 'node',
    'field' => 'date_argument',
    'relationship' => 'none',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'page' => 0,
      'story' => 0,
      'trash_collection' => 0,
      'trash_schedule' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_php' => '',
    'override' => array(
      'button' => 'Override',
    ),
    'default_options_div_prefix' => '',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'trash_collection' => 'trash_collection',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Override',
    ),
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
  'role' => array(),
  'perm' => '',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('title', 'Calendar');
$handler->override_option('header', '<?php print drupal_get_form(\'trash_track_lookup_form\'); ?>');
$handler->override_option('header_format', '3');
$handler->override_option('header_empty', 1);
$handler->override_option('footer', '<?php
// if a postal code is set
if(preg_match(\'/schedules\\/([^\\/]+)/\', $_GET[\'q\'], $matches))
{
    $postalCode = $matches[1];
    print \'<span class="trash_track_exportinfo_label">\' .
        t(\'Import this schedule into iCalendar, Google Calendar, or Microsoft Outlook: \') .
        \'</span><span class="trash_track_exportinfo_link">\' . l(\'Download\', "calendar/ical/$postalCode/" . date(\'Y\')) . \'</span>\';
}');
$handler->override_option('footer_format', '3');
$handler->override_option('footer_empty', 0);
$handler->override_option('items_per_page', 0);
$handler->override_option('use_more', 0);
$handler->override_option('style_plugin', 'calendar_nav');
$handler = $view->new_display('calendar', 'Calendar page', 'calendar_1');
$handler->override_option('style_options', NULL);
$handler->override_option('row_plugin', '');
$handler->override_option('row_options', NULL);
$handler->override_option('path', 'schedules');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('calendar_colors', array(
  '0' => array(),
));
$handler->override_option('calendar_colors_vocabulary', array());
$handler->override_option('calendar_colors_taxonomy', array());
$handler->override_option('calendar_popup', 0);
$handler->override_option('calendar_date_link', '');
$handler = $view->new_display('calendar_block', 'Calendar block', 'calendar_block_1');
$handler->override_option('style_options', NULL);
$handler->override_option('row_plugin', '');
$handler->override_option('row_options', NULL);
$handler->override_option('block_description', 'Calendar');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('calendar_period', 'Year view', 'calendar_period_1');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'display_type' => 'year',
  'name_size' => 1,
  'max_items' => 0,
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
));
$handler->override_option('calendar_type', 'year');
$handler = $view->new_display('calendar_period', 'Month view', 'calendar_period_2');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'display_type' => 'month',
  'name_size' => '99',
  'with_weekno' => '1',
  'date_fields' => NULL,
  'max_items' => 0,
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
));
$handler->override_option('calendar_type', 'month');
$handler = $view->new_display('calendar_period', 'Day view', 'calendar_period_3');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'name_size' => '99',
  'with_weekno' => 0,
  'max_items' => 0,
  'max_items_behavior' => 'more',
  'groupby_times' => 'hour',
  'groupby_times_custom' => '',
  'groupby_field' => '',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
));
$handler->override_option('calendar_type', 'day');
$handler = $view->new_display('calendar_period', 'Week view', 'calendar_period_4');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'name_size' => '99',
  'with_weekno' => 0,
  'max_items' => 0,
  'max_items_behavior' => 'more',
  'groupby_times' => 'hour',
  'groupby_times_custom' => '',
  'groupby_field' => '',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
));
$handler->override_option('calendar_type', 'week');
$handler = $view->new_display('calendar_period', 'Block view', 'calendar_period_5');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'display_type' => 'month',
  'name_size' => '1',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 0,
  'default' => 0,
  'calendar_block_1' => 'calendar_block_1',
));
$handler->override_option('calendar_type', 'month');
$handler = $view->new_display('calendar_ical', 'iCal feed', 'calendar_ical_1');
$handler->override_option('arguments', array(
  'title' => array(
    'default_action' => 'empty',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'glossary' => 0,
    'limit' => '0',
    'case' => 'none',
    'path_case' => 'none',
    'transform_dash' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'page' => 0,
      'story' => 0,
      'trash_collection' => 0,
      'trash_schedule' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
  'date_argument' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'date',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'date_fields' => array(
      'node_data_field_collection_dates.field_collection_dates_value' => 'node_data_field_collection_dates.field_collection_dates_value',
    ),
    'year_range' => '-3:+3',
    'date_method' => 'OR',
    'granularity' => 'month',
    'id' => 'date_argument',
    'table' => 'node',
    'field' => 'date_argument',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'page' => 0,
      'story' => 0,
      'trash_collection' => 0,
      'trash_schedule' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'trash_collection' => 'trash_collection',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('style_plugin', 'ical');
$handler->override_option('style_options', array(
  'mission_description' => FALSE,
  'description' => '',
  'summary_field' => 'field_collection_type_nice_value',
  'description_field' => 'body',
  'location_field' => 'title',
));
$handler->override_option('row_plugin', '');
$handler->override_option('path', 'calendar/ical');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 'calendar_block_1',
));
$handler->override_option('sitename_title', FALSE);
$handler = $view->new_display('block', 'Upcoming', 'block_1');
$handler->override_option('fields', array(
  'title' => array(
    'label' => '',
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'field' => 'title',
    'table' => 'node',
    'relationship' => 'none',
    'format' => 'default',
  ),
  'changed' => array(
    'label' => '',
    'link_to_node' => 0,
    'exclude' => 0,
    'id' => 'changed',
    'field' => 'changed',
    'table' => 'node',
    'relationship' => 'none',
    'date_format' => 'small',
    'format' => 'default',
  ),
));
$handler->override_option('arguments', array());
$handler->override_option('filters', array(
  'date_filter' => array(
    'operator' => '>=',
    'value' => array(
      'min' => NULL,
      'max' => NULL,
      'value' => NULL,
      'default_date' => 'now',
      'default_to_date' => '',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'date_fields' => array(
      'node_data_field_collection_dates.field_collection_dates_value' => 'node_data_field_collection_dates.field_collection_dates_value',
    ),
    'date_method' => 'OR',
    'granularity' => 'day',
    'form_type' => 'date_select',
    'default_date' => 'now',
    'default_to_date' => '',
    'year_range' => '-3:+3',
    'id' => 'date_filter',
    'table' => 'node',
    'field' => 'date_filter',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('title', 'Upcoming');
$handler->override_option('items_per_page', 5);
$handler->override_option('use_more', 1);
$handler->override_option('style_plugin', 'list');
$handler->override_option('style_options', array(
  'grouping' => '',
  'type' => 'ul',
));
$handler->override_option('block_description', 'Upcoming');
$handler->override_option('block_caching', -1);
}
<?php
/**
 * @file
 * crf_request.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crf_request_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'eva_field_collection_request';
  $view->description = 'Render field_collection for entity id';
  $view->tag = 'CRF';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'EVA_field_collection_request';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_request_deadline' => 'field_request_deadline',
    'item_id' => 'item_id',
    'field_reporting_type' => 'field_reporting_type',
    'field_request_requested_by' => 'field_request_requested_by',
    'field_request_recipients' => 'field_request_recipients',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_request_deadline' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reporting_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_request_requested_by' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_request_recipients' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Mah';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Boh';
  $handler->display->display_options['empty']['area']['format'] = 'simple';
  /* Relationship: Field collection item: Entity with the Request (field_collection_request) */
  $handler->display->display_options['relationships']['field_collection_request_node']['id'] = 'field_collection_request_node';
  $handler->display->display_options['relationships']['field_collection_request_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_collection_request_node']['field'] = 'field_collection_request_node';
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_collection_request_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_collection_request_node';
  /* Field: Content: Deadline for information submission */
  $handler->display->display_options['fields']['field_request_deadline']['id'] = 'field_request_deadline';
  $handler->display->display_options['fields']['field_request_deadline']['table'] = 'field_data_field_request_deadline';
  $handler->display->display_options['fields']['field_request_deadline']['field'] = 'field_request_deadline';
  $handler->display->display_options['fields']['field_request_deadline']['relationship'] = 'field_collection_request_node';
  $handler->display->display_options['fields']['field_request_deadline']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Field: Field collection item: Reporting types */
  $handler->display->display_options['fields']['field_reporting_type']['id'] = 'field_reporting_type';
  $handler->display->display_options['fields']['field_reporting_type']['table'] = 'field_data_field_reporting_type';
  $handler->display->display_options['fields']['field_reporting_type']['field'] = 'field_reporting_type';
  $handler->display->display_options['fields']['field_reporting_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Requested by */
  $handler->display->display_options['fields']['field_request_requested_by']['id'] = 'field_request_requested_by';
  $handler->display->display_options['fields']['field_request_requested_by']['table'] = 'field_data_field_request_requested_by';
  $handler->display->display_options['fields']['field_request_requested_by']['field'] = 'field_request_requested_by';
  $handler->display->display_options['fields']['field_request_requested_by']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Recipients */
  $handler->display->display_options['fields']['field_request_recipients']['id'] = 'field_request_recipients';
  $handler->display->display_options['fields']['field_request_recipients']['table'] = 'field_data_field_request_recipients';
  $handler->display->display_options['fields']['field_request_recipients']['field'] = 'field_request_recipients';
  $handler->display->display_options['fields']['field_request_recipients']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_request_recipients']['delta_offset'] = '0';
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_collection_request_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'request' => 'request',
  );

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_collection_request_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_collection_request_node';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'field-items';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'field';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Deadline for information submission */
  $handler->display->display_options['fields']['field_request_deadline']['id'] = 'field_request_deadline';
  $handler->display->display_options['fields']['field_request_deadline']['table'] = 'field_data_field_request_deadline';
  $handler->display->display_options['fields']['field_request_deadline']['field'] = 'field_request_deadline';
  $handler->display->display_options['fields']['field_request_deadline']['relationship'] = 'field_collection_request_node';
  $handler->display->display_options['fields']['field_request_deadline']['element_class'] = 'field-items';
  $handler->display->display_options['fields']['field_request_deadline']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_request_deadline']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_request_deadline']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_request_deadline']['element_wrapper_class'] = 'field';
  $handler->display->display_options['fields']['field_request_deadline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_request_deadline']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['exclude'] = TRUE;
  /* Field: Field collection item: Reporting types */
  $handler->display->display_options['fields']['field_reporting_type']['id'] = 'field_reporting_type';
  $handler->display->display_options['fields']['field_reporting_type']['table'] = 'field_data_field_reporting_type';
  $handler->display->display_options['fields']['field_reporting_type']['field'] = 'field_reporting_type';
  $handler->display->display_options['fields']['field_reporting_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_reporting_type']['element_class'] = 'field-items';
  $handler->display->display_options['fields']['field_reporting_type']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_reporting_type']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_reporting_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_reporting_type']['element_wrapper_class'] = 'field';
  $handler->display->display_options['fields']['field_reporting_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_reporting_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Requested by */
  $handler->display->display_options['fields']['field_request_requested_by']['id'] = 'field_request_requested_by';
  $handler->display->display_options['fields']['field_request_requested_by']['table'] = 'field_data_field_request_requested_by';
  $handler->display->display_options['fields']['field_request_requested_by']['field'] = 'field_request_requested_by';
  $handler->display->display_options['fields']['field_request_requested_by']['element_class'] = 'field-items';
  $handler->display->display_options['fields']['field_request_requested_by']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_request_requested_by']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_request_requested_by']['element_wrapper_class'] = 'field';
  $handler->display->display_options['fields']['field_request_requested_by']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_request_requested_by']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Recipients */
  $handler->display->display_options['fields']['field_request_recipients']['id'] = 'field_request_recipients';
  $handler->display->display_options['fields']['field_request_recipients']['table'] = 'field_data_field_request_recipients';
  $handler->display->display_options['fields']['field_request_recipients']['field'] = 'field_request_recipients';
  $handler->display->display_options['fields']['field_request_recipients']['element_class'] = 'field-items';
  $handler->display->display_options['fields']['field_request_recipients']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_request_recipients']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_request_recipients']['element_wrapper_class'] = 'field';
  $handler->display->display_options['fields']['field_request_recipients']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_request_recipients']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_request_recipients']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'report',
  );
  $handler->display->display_options['argument_mode'] = 'token';
  $handler->display->display_options['default_argument'] = '[node:field-collection-request-ref:item-id]';
  $translatables['eva_field_collection_request'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Mah'),
    t('Boh'),
    t('field_collection_request'),
    t('Nid'),
    t('Title'),
    t('Deadline for information submission'),
    t('Field collection item ID'),
    t('.'),
    t(','),
    t('Reporting types'),
    t('Requested by'),
    t('Recipients'),
    t('All'),
    t('EVA Field'),
  );
  $export['eva_field_collection_request'] = $view;

  return $export;
}

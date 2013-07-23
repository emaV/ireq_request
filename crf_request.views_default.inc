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
  $handler->display->display_options['fields']['title']['label'] = 'Request';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'field-items';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'field';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Field: Emergencies */
  $handler->display->display_options['fields']['field_emergencies']['id'] = 'field_emergencies';
  $handler->display->display_options['fields']['field_emergencies']['table'] = 'field_data_field_emergencies';
  $handler->display->display_options['fields']['field_emergencies']['field'] = 'field_emergencies';
  $handler->display->display_options['fields']['field_emergencies']['relationship'] = 'field_collection_request_node';
  $handler->display->display_options['fields']['field_emergencies']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_emergencies']['element_class'] = 'field-items';
  $handler->display->display_options['fields']['field_emergencies']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_emergencies']['element_label_class'] = 'field-label';
  $handler->display->display_options['fields']['field_emergencies']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_emergencies']['element_wrapper_class'] = 'field';
  $handler->display->display_options['fields']['field_emergencies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_emergencies']['hide_empty'] = TRUE;
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
  $handler->display->display_options['fields']['field_request_recipients']['label'] = 'Requested to';
  $handler->display->display_options['fields']['field_request_recipients']['exclude'] = TRUE;
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
    t('Request'),
    t('Emergencies'),
    t('Requested to'),
  );
  $export['eva_field_collection_request'] = $view;

  $view = new view();
  $view->name = 'eva_report_workflow';
  $view->description = '';
  $view->tag = 'CRF';
  $view->base_table = 'node_revision';
  $view->human_name = 'EVA_report_workflow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
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
  );
  /* Relationship: Workbench Moderation: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content revision: Log message */
  $handler->display->display_options['fields']['log']['id'] = 'log';
  $handler->display->display_options['fields']['log']['table'] = 'node_revision';
  $handler->display->display_options['fields']['log']['field'] = 'log';
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'long';
  /* Sort criterion: Workbench Moderation: Moderation state order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'workbench_moderation_states';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_1');
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'report',
  );
  $translatables['eva_report_workflow'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Node'),
    t('State'),
    t('Log message'),
    t('Timestamp'),
    t('All'),
    t('EVA Field'),
  );
  $export['eva_report_workflow'] = $view;

  return $export;
}

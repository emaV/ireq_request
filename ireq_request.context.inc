<?php
/**
 * @file
 * ireq_request.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ireq_request_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ireq_type_report';
  $context->description = 'IREQ - Report';
  $context->tag = 'IREQ';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'report' => 'report',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('IREQ');
  t('IREQ - Report');
  $export['ireq_type_report'] = $context;

  return $export;
}

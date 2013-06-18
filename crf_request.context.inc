<?php
/**
 * @file
 * crf_request.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crf_request_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crf_type_report';
  $context->description = 'CRF - Report';
  $context->tag = 'CRF';
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
  t('CRF');
  t('CRF - Report');
  $export['crf_type_report'] = $context;

  return $export;
}

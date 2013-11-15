<?php
/**
 * @file
 * ireq_request.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ireq_request_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create report content'.
  $permissions['create report content'] = array(
    'name' => 'create report content',
    'roles' => array(
      'IREQ_user' => 'IREQ_user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create request content'.
  $permissions['create request content'] = array(
    'name' => 'create request content',
    'roles' => array(
      'IREQ_user' => 'IREQ_user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any report content'.
  $permissions['delete any report content'] = array(
    'name' => 'delete any report content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any request content'.
  $permissions['delete any request content'] = array(
    'name' => 'delete any request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own report content'.
  $permissions['delete own report content'] = array(
    'name' => 'delete own report content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own request content'.
  $permissions['delete own request content'] = array(
    'name' => 'delete own request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any report content'.
  $permissions['edit any report content'] = array(
    'name' => 'edit any report content',
    'roles' => array(
      'IREQ_manager' => 'IREQ_manager',
      'IREQ_user' => 'IREQ_user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any request content'.
  $permissions['edit any request content'] = array(
    'name' => 'edit any request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own report content'.
  $permissions['edit own report content'] = array(
    'name' => 'edit own report content',
    'roles' => array(
      'IREQ_user' => 'IREQ_user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own request content'.
  $permissions['edit own request content'] = array(
    'name' => 'edit own request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'moderate report state from draft to needs_review'.
  $permissions['moderate report state from draft to needs_review'] = array(
    'name' => 'moderate report state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate report state from draft to published'.
  $permissions['moderate report state from draft to published'] = array(
    'name' => 'moderate report state from draft to published',
    'roles' => array(
      'IREQ_user' => 'IREQ_user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate report state from needs_review to draft'.
  $permissions['moderate report state from needs_review to draft'] = array(
    'name' => 'moderate report state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate report state from needs_review to published'.
  $permissions['moderate report state from needs_review to published'] = array(
    'name' => 'moderate report state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view any unpublished report content'.
  $permissions['view any unpublished report content'] = array(
    'name' => 'view any unpublished report content',
    'roles' => array(
      'IREQ_user' => 'IREQ_user',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}

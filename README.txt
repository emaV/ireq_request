crf_request
-----------

== Module (crf_request.module)

=== Block hooks

crf_request_block_info
crf_request_block_view

  Block qith add request link


=== Form alter hooks
crf_request_form_request_node_form_alter
crf_request_field_collection_request_preview_validate
crf_request_field_collection_request_preview_submit
crf_request_field_collection_request_cancel_preview_submit

  Preview for the requests (field_collection_request)

=== Theme hooks
crf_request_theme
theme_field_collection_request_preview

  Theme request (field_collection_request) preview


== Content Types

Report
Request


== Field bases/instances

field_collection_item-field_collection_request-field_append_to_alert_email
field_collection_item-field_collection_request-field_reporting_type
field_collection_item-field_collection_request-field_request_recipients
field_collection_item-field_collection_request-field_request_requested_by
field_collection_item-field_collection_request-field_report

node-report-field_collection_request_ref
node-report-field_file
node-report-field_recipient
node-report-field_report_description

node-request-field_collection_request
node-request-field_request_deadline
node-request-field_internal_report

taxonomy_term-reporting_types-field_content_type


== Rules (crf_request.rules_defaults.inc)
rules_request_submission - Request submission (report creation and notification)
rules_content_published - Workflow content type published (notification on report finalization)
rules_crf_workflow_simple - CRF Workflow simple (needs input > finalization).

=== Components (used by main rules)
rules_check_report_references - Update report adding backreferences
rules_create_report_from_report_term - intermediate rule
rules_create_report_from_request_item - intermediate rule
rules_email_notification_body - set notification body
rules_fix_report_url - fix request report url (use provided url only if is an external)

== Taxonomy (crf_request.features.taxonomy.inc)

reporting_types - Reporting types


== Views (crf_request.views_default.inc)

eva_field_collection_request - Render field_collection for entity id




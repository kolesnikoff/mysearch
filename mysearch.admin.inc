<?php

/**
 * @file
 * Administrative page callback for the MySearch module.
 */

/**
 * General configuration form for searching module.
 */
function mysearch_admin_settings() {
  $form = array();

  // Fetch all content types and create simple array.
  $content_types = node_type_get_types();
  $types = array();
  foreach ($content_types as $key => $type) {
    $types[$key] = $type->name;
  }
  ksort($types);

  $form['mysearch_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types for MySearch module'),
    '#description' => t('Allow to search into different content types.
      If nothing is selected search will be processed through all content types.'),
    '#default_value' => variable_get('mysearch_content_types', array()),
    '#options'  => $types,
  );

  return system_settings_form($form);
}

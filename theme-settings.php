<?php

  function nova_bs_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['layout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Layout'),
  );

  $form['layout']['columns_list'] = array(
      '#type'  => 'textfield',
      '#title' => t('Breakpoints'),
      '#description' => t('List of unitless column widths, separated by spaces, i. e. `1 2 3 4 5`'),
      '#default_value' => theme_get_setting('columns_list'),
      '#size' => 8,
      '#maxlength' => 10,
    );

  }
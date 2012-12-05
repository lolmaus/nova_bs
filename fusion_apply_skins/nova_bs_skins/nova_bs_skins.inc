<?php
/////////////////
// Fusion Apply
/////////////////

function nova_bs_fusion_apply_skin_nova_bs_skins_info() {
  $skins = array();

  $skins['fusion_skins_block_positioning'] = array(
    'title' => t('Block position'),
    'type' => 'select',
    'description' => t('Change the position of this block (default is to float to the left)'),
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => array(
      'fusion-right' => array(
        'title' => 'Float block to the right',
        'class' => array('fusion-right'),
      ),
      'fusion-center' => array(
        'title' => 'Position block in the center',
        'class' => array('fusion-center'),
      ),
      'fusion-clear' => array(
        'title' => 'Clear floats (block drops to a new line)',
        'class' => array('fusion-clear'),
      ),
    ),
  );

  return $skins;
}
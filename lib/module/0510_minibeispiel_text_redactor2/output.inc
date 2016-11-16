<?php

if(!rex_addon::get('redactor2')->isAvailable()) {
  echo rex_view::error('Dieses Modul ben&ouml;tigt das "redactor2" Addon!');
}

if ('REX_VALUE[id=1 isset=1]') {
  echo 'REX_VALUE[id="1" output="html"]';
}

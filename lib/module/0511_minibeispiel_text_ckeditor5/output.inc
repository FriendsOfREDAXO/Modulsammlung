<?php

if(!rex_addon::get('cke5')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "CKEditor5" Addon!');
}

if ('REX_VALUE[id=1 isset=1]') {
    echo 'REX_VALUE[id="1" output="html"]';
}

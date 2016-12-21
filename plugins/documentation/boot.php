<?php
// CSS und JavaScript für Dokumentation einbinden
if (rex::isBackend() && is_object(rex::getUser())) {
    $plugindir = basename(__DIR__);
    if (rex_be_controller::getCurrentPagePart(2) == $plugindir) {
        rex_view::addCssFile($this->getAssetsUrl('documentation.css'));
        rex_view::addJsFile($this->getAssetsUrl('documentation.js'));
    }
}

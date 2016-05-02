<?php

/** @var rex_addon $this */

$content = '';

if (rex_post('config-submit', 'boolean')) {
    $this->setConfig(rex_post('config', [
        ['url', 'string'],
        ['ids', 'array[int]'],
    ]));

    $content .= rex_view::info($this->i18n('config_saved'));
}

$content .= '
<div class="rex-form">
    <form action="' . rex_url::currentBackendPage() . '" method="post">
        <fieldset>';

$formElements = [];

$n = [];
$n['label'] = '<label for="rex-dummy-config-url">' . $this->i18n('config_url') . '</label>';
$n['field'] = '<input type="text" id="rex-dummy-config-url" name="config[url]" value="' . $this->getConfig('url') . '"/>';
$formElements[] = $n;

$n = [];
$n['label'] = '<label for="rex-dummy-config-ids">' . $this->i18n('config_ids') . '</label>';
$select = new rex_select();
$select->setId('rex-dummy-config-ids');
$select->setMultiple();
$select->setName('config[ids][]');
for ($i = 1; $i < 6; ++$i) {
    $select->addOption($i, $i);
}
$select->setSelected($this->getConfig('ids'));
$n['field'] = $select->get();
$formElements[] = $n;

$fragment = new rex_fragment();
$fragment->setVar('elements', $formElements, false);
$content .= $fragment->parse('core/form/form.php');

$content .= '
        </fieldset>

        <fieldset class="rex-form-action">';

$formElements = [];

$n = [];
$n['field'] = '<input type="submit" name="config-submit" value="' . $this->i18n('config_save') . '" ' . rex::getAccesskey($this->i18n('config_save'), 'save') . ' />';
$formElements[] = $n;

$fragment = new rex_fragment();
$fragment->setVar('elements', $formElements, false);
$content .= $fragment->parse('core/form/submit.php');

$content .= '
        </fieldset>

    </form>
</div>';

$fragment = new rex_fragment();
$fragment->setVar('class', 'edit');
$fragment->setVar('title', $this->i18n('config'));
$fragment->setVar('body', $content, false);
echo $fragment->parse('core/page/section.php');

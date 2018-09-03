<?php
if(!rex_addon::get('cke5')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "CKEditor5" Addon!');
}
?>
<fieldset class="form-horizontal">
    <div class="form-group">
        <label class="col-sm-12 text-left" for="value-1">Text</label>
        <div class="col-sm-12">
            <textarea class="form-control cke5-editor" data-profile="default" data-lang="<?php echo \Cke5\Utils\Cke5Lang::getUserLang(); ?>" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
        </div>
    </div>
</fieldset>



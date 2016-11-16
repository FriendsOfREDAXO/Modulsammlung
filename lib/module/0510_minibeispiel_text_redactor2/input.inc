<?php
if(!rex_addon::get('redactor2')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "redactor2" Addon!');
}
?>
<fieldset class="form-horizontal">
  <div class="form-group">
    <label class="col-sm-2 control-label" for="value-1">Text</label>
    <div class="col-sm-10">
      <textarea class="form-control redactorEditor2-full" id="value-1" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
    </div>
  </div>
</fieldset>

<?php
if(!rex_addon::get('markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "markitup" Addon!');
}
?>
<div class="form-group">
  <label class="col-sm-2">Text</label>
  <div class="col-sm-10">
    <textarea class="form-control markitupEditor-textile_full" id="value-1" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
  </div>
</div>

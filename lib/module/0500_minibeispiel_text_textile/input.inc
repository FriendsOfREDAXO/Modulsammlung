<?
if(!rex_addon::get('textile')->isAvailable()) {
  echo rex_view::error('Dieses Modul ben&ouml;tigt das "Textile" Addon!');
}
?>
<div class="form-group">
  <label class="col-sm-2">Text</label>
  <div class="col-sm-10">
    <textarea cols="1" rows="6" class="form-control" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
  </div>
</div>

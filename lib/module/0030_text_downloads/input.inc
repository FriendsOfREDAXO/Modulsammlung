<?php

if(!rex_addon::get('markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
} else {
  if (!markitup::profileExists('simple')) {
    markitup::insertProfile('simple', 'Angelegt durch das Addon Modulsammlung', 'textile', 300, 800, 'relative', 'bold,italic,underline,deleted,quote,sub,sup,code,unorderedlist,grouplink[internal|external|mailto]');
  }
}

?>
<div id="text_download" class="modul-content">
  <div class="form-horizontal">
    <h3>Text / Download</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label">Überschrift</label>
      <div class="col-sm-9">
        <input class="form-control" name="REX_INPUT_VALUE[1]" value="REX_VALUE[1]" type="text" />
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Text</label>
      <div class="col-sm-9">
          <textarea id="markitup_textile_1" class="form-control markitup markitupEditor-simple" name="REX_INPUT_VALUE[2]">REX_VALUE[2]</textarea>
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Dateien</label>
      <div class="col-sm-9">
          REX_MEDIALIST[id="1" widget="1"]
      </div>
    </div>
  </div>

</div>


<style>
.modul-content {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

.modul-content h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

.modul-content .control-label {
  font-weight: normal;
  font-size: 12px !important;
}


input.form-control,
select.form-control,
textarea.form-control {
  background: #fff !important;
}

#markitup_textile_1 {
  min-height: 200px;
}

</style>

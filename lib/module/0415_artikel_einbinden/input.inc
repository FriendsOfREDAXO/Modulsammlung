<div id="artikel_einbinden" class="modul-content">
  <div>
    <div class="form-horizontal">
      <h3>Artikel einbinden</h3>
        <div class="form-group">
        <label class="col-sm-3 control-label">Artikel</label>
        <div class="col-sm-9">
          REX_LINK[id=1 widget=1]
        </div>
      </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Mit Template einbinden?</label>
      <div class="col-sm-9">
        <div class="rex-select-style">
          <select name="REX_INPUT_VALUE[2]">
            <option value="nein"<?php if ('REX_VALUE[2]' == 'nein') echo ' selected'; ?>>nein</option>
            <option value="ja"<?php if ('REX_VALUE[2]' == 'ja') echo ' selected'; ?>>ja</option>
          </select>
        </div>
      </div>
    </div>
  </div>
</div>


<style>
#artikel_einbinden.modul-content {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#artikel_einbinden.modul-content h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#artikel_einbinden.modul-content .control-label {
  font-weight: normal;
  font-size: 12px !important;
}

#artikel_einbinden.modul-content input.form-control,
#artikel_einbinden.modul-content select.form-control,
#artikel_einbinden.modul-content textarea.form-control {
  background: #fff !important;
}

</style>

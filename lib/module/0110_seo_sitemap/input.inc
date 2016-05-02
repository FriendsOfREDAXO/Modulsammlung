<?php
if(!rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
} else {
  if (!rex_markitup::profileExists('simple')) {
  rex_markitup::insertProfile('simple', 'Angelegt durch das Addon Modulsammlung', 'textile', 'bold,italic,underline,deleted,quote,sub,sup,code,unorderedlist,link[internal|external|mailto]');
  }
  if (!rex_addon::get('textile')->isAvailable()) {
      echo rex_view::error('Dieses Modul benötigt das "textile" Addon!');
  }
}

?><div id="sitemap" class="modul-content">
  <div>
    <div class="form-horizontal">
      <h3>Sitemap</h3>
        <div class="form-group">
        <label class="col-sm-3 control-label">Text</label>
        <div class="col-sm-9">
          <textarea id="markitup_textile_1" class="form-control markitup markitupEditor-simple" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
        </div>
      </div>
      <div class="form-group">
        <label class="col-sm-3 control-label">Artikel anzeigen</label>
        <div class="col-sm-9">
          <div class="rex-select-style">
            <select name="REX_INPUT_VALUE[2]">
              <option value="nein"<?php if ('REX_VALUE[2]' == 'nein') echo ' selected'; ?>>nein</option>
              <option value="ja"<?php if ('REX_VALUE[2]' == 'ja') echo ' selected'; ?>>ja</option>
              </select>
            </div>
          </div>
        </div>
      <div class="form-group">
        <label class="col-sm-3 control-label">Startartikel anzeigen</label>
        <div class="col-sm-9">
          <div class="rex-select-style">
            <select name="REX_INPUT_VALUE[3]">
              <option value="nein"<?php if ('REX_VALUE[3]' == 'nein') echo ' selected'; ?>>nein</option>
              <option value="ja"<?php if ('REX_VALUE[3]' == 'ja') echo ' selected'; ?>>ja</option>
              </select>
            </div>
          </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">SEO Infos anzeigen</label>
          <div class="col-sm-9">
            <div class="rex-select-style">
              <select name="REX_INPUT_VALUE[4]">
                <option value="nein"<?php if ('REX_VALUE[4]' == 'nein') echo ' selected'; ?>>nein</option>
                <option value="ja"<?php if ('REX_VALUE[4]' == 'ja') echo ' selected'; ?>>ja</option>
              </select>
            </div>
          </div>
        </div>


 <div  id="anleitung" >
 <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-text"><span class="caret"></span>Erklärung</h3></div>
  <div id="collapse-text" class="panel-collapse collapse">

    <div class="form-group">
      <label class="col-sm-3 control-label">Text</label>
        <div class="col-sm-9">
          <p>Text, der neben der Sitemap dargestellt wird.</p>
        </div>
    </div>

    <div class="form-group">
      <label class="col-sm-3 control-label">Artikel anzeigen</label>
        <div class="col-sm-9">
          <p>Artikel werden ausgegeben</p>
        </div>
    </div>

    <div class="form-group">
      <label class="col-sm-3 control-label">Startartikel anzeigen</label>
        <div class="col-sm-9">
          <p>Startartikel werden ausgegeben</p>
        </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">SEO Infos anzeigen</label>
        <div class="col-sm-9">
          <p>Es werde die Informationen "Title" und "Description" ausgegeben. Am besten auf "nein" stellen sobald die Webseite online ist.</p>
        </div>
    </div>

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

.markitup {
  min-height: 200px;
}

#anleitung .control-label {
  margin-top: -6px;
}

#anleitung {
  margin-top: 30px;
}

#anleitung .panel-heading {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  text-align: left;
  margin-bottom: 20px;
  border: none;
}
#anleitung .panel-heading span {
  margin-right: 5px;
}

#anleitung .panel-heading:hover  {
  color: #000;
}
</style>

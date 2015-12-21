<?php

$editor                 = 0;

if(!rex_addon::get('rex_redactor')->isAvailable() AND !rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "Redactor" oder das "MarkItUp" Addon!');
}
if(rex_addon::get('rex_redactor')->isAvailable()) {
  $editor = 'redactor';

  if (!rex_redactor::profileExists('simple')) {
  rex_redactor::insertProfile('simple', 'Angelegt durch das Addon MOdulsammlung', 'bold,italic,underline');
  }

}

if(rex_addon::get('rex_markitup')->isAvailable()) {
  $editor = 'markitup';

  if (!rex_markitup::profileExists('simple')) {
    rex_markitup::insertProfile('simple', 'Angelegt durch das Addon MOdulsammlung', 'textile', 'bold,italic,underline');
  }
  if (!rex_addon::get('textile')->isAvailable()) {
      echo rex_view::error('Dieses Modul benötigt das "textile" Addon!');
  }
}

?><div class="modul-content">
  <div>
    <div class="form-horizontal">
      <h3>Sitemap</h3>
        <div class="form-group">
        <label class="col-sm-3 control-label">Text</label>
        <div class="col-sm-9">
          <textarea class="form-control <?php echo $editor.' '.$editor; ?>Editor-simple" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
        </div>
      </div>
      <div class="form-group">
        <label class="col-sm-3 control-label">Artikel anzeigen</label>
        <div class="col-sm-9">
          <div class="select-style">
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
          <div class="select-style">
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
            <div class="select-style">
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
          <p>Es werde die Informationen "Title" und "Description" ausgegeben. Am besten auf "nein" stellen sobald die Webseite onlione ist.</p>
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

.select-style {
    border: 1px solid #cccccc;
    width: 100%;
    overflow: hidden;
    background: #fff url("data:image/png;base64,R0lGODlhDwAUAIABAAAAAP///yH5BAEAAAEALAAAAAAPABQAAAIXjI+py+0Po5wH2HsXzmw//lHiSJZmUAAAOw==") no-repeat 98% 50%;
    margin-bottom: 6px;
}
.select-style select {
    padding: 5px 8px;
    width: 100%;
    border: none;
    box-shadow: none;
    background: transparent;
    background-image: none;
    -webkit-appearance: none;
    -moz-appearance:none;
    -webkit-border-radius: 0px;
}
.select-style select:focus {
    outline: none;
}
.select-style select:hover {
    cursor: pointer;
}

input.form-control,
select.form-control,
textarea.form-control {
  background: #fff !important;
}

.redactor-editor,
.markitup {
  min-height: 200px;
}

.redactor-box {
  border: 1px solid #ccc;
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
  text-align: right;
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

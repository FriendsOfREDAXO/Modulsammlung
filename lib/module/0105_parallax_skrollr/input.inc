<?php
if(!rex_addon::get('markitup')->isAvailable() && !rex_addon::get('redactor2')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" oder das "Redactor 2" Addon!');
}
if (rex_addon::get('markitup')->isAvailable() && !markitup::profileExists('simple')) {
  markitup::insertProfile('simple', 'Angelegt durch das Addon Modulsammlung', 'textile', 300, 800, 'relative', 'bold,italic,underline,deleted,quote,sub,sup,code,unorderedlist,grouplink[internal|external|mailto]');
}

if (rex_addon::get('redactor2')->isAvailable() && !redactor2::profileExists('simple')) {
    redactor2::insertProfile('simple', 'Angelegt durch das Addon Modulsammlung', '300', '800', 'relative','bold, italic, underline, deleted, sub, sup,  unorderedlist, orderedlist, grouplink[email|external|internal|media], cleaner');
}
?>
<div id="parallax" class="modul-content">
  <div class="form-horizontal">
    <h3>Parallax</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label" for="headline-level">Bild</label>
      <div class="col-sm-9">
        <div class="btn-group btn-group-vertical" data-toggle="buttons">
          REX_MEDIA[id=1 widget=1]
        </div>
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Überschrift</label>
      <div class="col-sm-9">
        <input class="form-control" name="REX_INPUT_VALUE[1]" value="REX_VALUE[1]" type="text" />
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Text</label>
      <div class="col-sm-9">
      <?php
        if (rex_addon::get('redactor2')->isAvailable()) {
          echo'
            <textarea class="form-control redactorEditor2-simple" id="value-2" name="REX_INPUT_VALUE[2]">REX_VALUE[2]</textarea>';
        } else {
          echo '
            <textarea id="markitup_textile_1" class="form-control markitup markitupEditor-simple" name="REX_INPUT_VALUE[2]">REX_VALUE[2]</textarea>
          ';
        }
      ?>
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Bildposition 1</label>
      <div class="col-sm-9">
        <div class="rex-select-style">
          <select id="bildpos1" name="REX_INPUT_VALUE[3]">
            <?php
              foreach (array('0%', '10%', '20%', '30%', '40%', '50%', '60%', '70%', '80%', '90%', '100%') as $value) {
              echo '<option value="'.$value.'" ';
              if ( "REX_VALUE[3]"=="$value" ) {
                echo 'selected="selected" ';
              }
                echo '>'.$value.'</option>';
              }
            ?>
          </select>
        </div>
      </div>
    </div>
	<div class="form-group">
      <label class="col-sm-3 control-label">Bildposition 2</label>
      <div class="col-sm-9">
        <div class="rex-select-style">
          <select id="bildpos2" name="REX_INPUT_VALUE[4]">
            <?php
              foreach (array('0%', '10%', '20%', '30%', '40%', '50%', '60%', '70%', '80%', '90%', '100%') as $value) {
              echo '<option value="'.$value.'" ';
              if ( "REX_VALUE[4]"=="$value" ) {
                echo 'selected="selected" ';
              }
                echo '>'.$value.'</option>';
              }
            ?>
          </select>
        </div>
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Höhe</label>
      <div class="col-sm-9">
        <input class="form-control" name="REX_INPUT_VALUE[5]" value="REX_VALUE[5]" type="text" />
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Breite</label>
      <div class="col-sm-9 ">
        <div class="rex-select-style">
          <select id="breite" name="REX_INPUT_VALUE[6]">
            <?php
              foreach (array('100% Browserbreite', 'So breit wie der Inhalt') as $value) {
                echo '<option value="'.$value.'" ';

                if ( "REX_VALUE[6]"=="$value" ) {
                  echo 'selected="selected" ';
                }
                echo '>'.$value.'</option>';
              }
            ?>
          </select>
        </div>
      </div>
    </div>
  </div>
</div>
<style>
#parallax.modul-content {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#parallax.modul-content h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#parallax.modul-content .control-label {
  font-weight: normal;
  margin-top: 2px;
  font-size: 12px !important;
}
</style>


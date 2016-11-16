<?php
if(!rex_addon::get('markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
} else {
  if (!markitup::profileExists('supersimple')) {
    markitup::insertProfile ('supersimple', 'Angelegt durch das Addon Modulsammlung', 'textile', 300, 800, 'relative', 'bold,italic,underline');
  }
}
?>

<div id="slider_modul_input">
  <div id="bereich1" class="">
    <div class="form-horizontal">
    <h3>Slider mit/ohne Text</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label">Sliderbilder</label>
      <div class="col-sm-9">
          REX_MEDIALIST[id="1" widget="1"]
      </div>
    </div>
    <div class="form-group">
    <label class="col-sm-3 control-label">Automatisch abspielen</label>
      <div class="col-sm-9">
        <div class="rex-select-style">
          <select name="REX_INPUT_VALUE[1]">
            <option value="nein"<?php if ('REX_VALUE[1]' == 'nein') echo ' selected'; ?>>nein</option>
            <option value="ja"<?php if ('REX_VALUE[1]' == 'ja') echo ' selected'; ?>>ja</option>
          </select>
        </div>
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Paginierung anzeigen</label>
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
    <label class="col-sm-3 control-label">Navigation anzeigen</label>
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
  <label class="col-sm-3 control-label">Anzahl der Bilder</label>
    <div class="col-sm-9 ">
      <div class="rex-select-style">
        <select id="trennerbreite" name="REX_INPUT_VALUE[4]">
        <?php
          foreach (array('1', '2', '3','4','5','6','7','8','9','10') as $value) {
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
  <label class="col-sm-3 control-label">Breite des Sliders</label>
    <div class="col-sm-9 ">
      <div class="rex-select-style">
        <select id="trennerbreite" name="REX_INPUT_VALUE[5]">
        <?php
          foreach (array('100% Browserbreite', 'So breit wie der Inhalt') as $value) {
            echo '<option value="'.$value.'" ';

            if ( "REX_VALUE[5]"=="$value" ) {
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
    <label class="col-sm-3 control-label">Text</label>
    <div class="col-sm-9">
      <textarea class="form-control markitupEditor-supersimple" id="value-6" name="REX_INPUT_VALUE[6]">REX_VALUE[6]</textarea>
    </div>
  </div>

  <div  id="anleitung" >
    <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-text"><span class="caret"></span>Erklärung</div>
      <div id="collapse-text" class="panel-collapse collapse">
        <div class="form-group">
          <label class="col-sm-3 control-label">Automatisch abspielen</label>
          <div class="col-sm-9">
            <p>Spielt die Slideshow automatisch ab.</p>
          </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Paginierung anzeigen</label>
            <div class="col-sm-9">
              <p>Zeigt die Paginierung an.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Navigation anzeigen</label>
            <div class="col-sm-9">
              <p>Zeigt die Navigation an.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Breite des Sliders</label>
            <div class="col-sm-9">
              <p>Ändert die Breite des SliderContainers. 100% Browserbreite ist nicht möglich sofern es eine Seitenleiste (Inhalt / Navigation) im Content gibt.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Text</label>
            <div class="col-sm-9">
              <p>Ermöglicht es einen Text neben bzw. unter dem Slider darzustellen.</p>
            </div>
        </div>
      </div>
    </div>
  </div>
</div>

<style>
#slider_modul_input {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#slider_modul_input h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#slider_modul_input .control-label {
  font-weight: normal;
  font-size: 12px !important;
}

#slider_modul_input input.form-control,
#slider_modul_input select.form-control,
#slider_modul_input textarea.form-control {
  background: #fff !important;
}

#slider_modul_input #anleitung .control-label {
  margin-top: -6px;
}

#slider_modul_input #anleitung {
  margin-top: 30px;
}

#slider_modul_input #anleitung .panel-heading {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  text-align: left;
  margin-bottom: 20px;
  border: none;
}
#slider_modul_input #anleitung span {
  margin-right: 5px;
}

#slider_modul_input #anleitung .panel-heading:hover  {
  color: #000;
}

#markitup_textile_1 {
  min-height: 200px;
}

</style>

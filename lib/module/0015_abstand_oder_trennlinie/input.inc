<div id="trenner_modul_input">
  <div id="bereich1" class="">
    <div class="form-horizontal">
    <h3>Abstand oder Trennlinie mit/ohne Grafik</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label">Abstand in PX</label>
      <div class="col-sm-9">
        <input class="form-control" name="REX_INPUT_VALUE[1]" value="REX_VALUE[1]" type="text" />
      </div>
    </div>
    <div class="form-group">
    <label class="col-sm-3 control-label">Linie anzeigen</label>
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
      <label class="col-sm-3 control-label">Grafik anzeigen</label>
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
  <label class="col-sm-3 control-label">Breite des Trenners</label>
    <div class="col-sm-9 ">
      <div class="rex-select-style">
        <select id="trennerbreite" name="REX_INPUT_VALUE[4]">
        <?php
          foreach (array('100% Browserbreite', 'So breit wie der Inhalt') as $value) {
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

  <div  id="anleitung" >
    <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-text"><span class="caret"></span>Erklärung</div>
      <div id="collapse-text" class="panel-collapse collapse">
        <div class="form-group">
          <label class="col-sm-3 control-label">Abstand in PX</label>
          <div class="col-sm-9">
            <p>Sofern das Feld "Abstand in PX" leer gelassen wird wird ein default Abstand von 30px benutzt.</p>
          </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Linie anzeigen</label>
            <div class="col-sm-9">
              <p>Eine Trennlinie wird angezeigt.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Grafik anzeigen</label>
            <div class="col-sm-9">
              <p>Zeigt eine Trennline und eine 30x30px große Grafik aus dem Medienpool (trenner.png) an.</p>
            </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Breite des Trenners</label>
            <div class="col-sm-9">
              <p>Ändert die Breite des Trenners. 100% Browserbreite ist nicht möglich sofern es eine Seitenleiste (Inhalt / Navigation) im Content gibt.</p>
            </div>
        </div>
      </div>
    </div>
  </div>
</div>

<style>
#trenner_modul_input {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#trenner_modul_input h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#trenner_modul_input .control-label {
  font-weight: normal;
  font-size: 12px !important;
}

#trenner_modul_input input.form-control,
#trenner_modul_input select.form-control,
#trenner_modul_input textarea.form-control {
  background: #fff !important;
}

#trenner_modul_input #anleitung .control-label {
  margin-top: -6px;
}

#trenner_modul_input #anleitung {
  margin-top: 30px;
}

#trenner_modul_input #anleitung .panel-heading {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  text-align: left;
  margin-bottom: 20px;
  border: none;
}
#trenner_modul_input #anleitung span {
  margin-right: 5px;
}

#trenner_modul_input #anleitung .panel-heading:hover  {
  color: #000;
}
</style>

<div id="unite_gallery" class="modul-content">
  <div class="form-horizontal">
    <h3 class="ueberschrift">Bildergalerie</h3>
    <div class="form-group">
      <label class="col-sm-2 control-label" for="headline">Bilder</label>
    <div class="col-sm-10">
      REX_MEDIALIST[id="1" widget="1"]
    </div>
  </div>

  <h3 class="ueberschrift">Einstellungen</h3>
  <div class="form-group">
    <label class="col-sm-3 control-label">Art der Galerie</label>
    <div class="col-sm-9">
      <div class="rex-select-style">
        <select id="galerieart" name="REX_INPUT_VALUE[1]">
          <option value="standard"<?php if ('REX_VALUE[1]' == 'standard') echo ' selected'; ?>>standard</option>
           <option value="fleximages"<?php if ('REX_VALUE[1]' == 'fleximages') echo ' selected'; ?>>mosaik</option>
        </select>
      </div>
    </div>
  </div>
 <div class="form-group">
        <label class="col-sm-3 control-label">Breite der Galerie</label>
        <div class="col-sm-9 ">
          <div class="rex-select-style">
            <select id="glaeriebreite" name="REX_INPUT_VALUE[4]">
            <?php
              foreach (array('So breit wie der Inhalt','100% Browserbreite') as $value) {
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

  <div class="form-group weitereeinstellungen">
    <label class="col-sm-3 control-label">Höhe der Bilder</label>
    <div class="col-sm-9">
      <input class="form-control" name="REX_INPUT_VALUE[2]" value="REX_VALUE[2]" type="text" />
    </div>
  </div>

  <div class="form-group weitereeinstellungen">
    <label class="col-sm-3 control-label">unvollständige Zeilen</label>
    <div class="col-sm-9">
      <div class="rex-select-style">
        <select name="REX_INPUT_VALUE[3]">
          <option value="anzeigen"<?php if ('REX_VALUE[3]' == 'anzeigen') echo ' selected'; ?>>anzeigen</option>
           <option value="verbergen"<?php if ('REX_VALUE[3]' == 'verbergen') echo ' selected'; ?>>verbergen</option>
        </select>
      </div>
    </div>
  </div>

<div  id="anleitung" >
 <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-text"><span class="caret"></span>Erklärung</div>
  <div id="collapse-text" class="panel-collapse collapse">

    <div class="form-group">
      <label class="col-sm-3 control-label">Art der Galerie</label>
        <div class="col-sm-9">
          <p>Einfach mal ausprobieren und angucken :-)</p>
        </div>
    </div>

    <div class="form-group">
      <label class="col-sm-3 control-label">Breite der Galerie</label>
      <div class="col-sm-9">
        <p>Ändert die Breite der Galerie. 100% Browserbreite ist nicht möglich sofern es eine Seitenleiste (Inhalt / Navigation) im Content gibt.</p>
      </div>
    </div>

    <div class="form-group">
      <label class="col-sm-3 control-label">Höhe der Bilder</label>
        <div class="col-sm-9">
          <p>Aus dieser Angabe ergibt sich die Höhe der Zeilen. Sofern kein Wert angegeben wird wird eine Höhe von 200px benutzt.</p>
        </div>
    </div>

    <div class="form-group">
      <label class="col-sm-3 control-label">Unvollständige Zeilen</label>
        <div class="col-sm-9">
          <p>Die letzte Zeile der Galerie kann - bedingt durch die Anzahl der Bilder - "unvollständig" sein. Das kann durch die Auswahl von "verbergen" unterbunden werden. Bilder die dazu führen, dass eine Zeile unvollständig angezeigt wird werden dann nicht angezeigt.</p>
        </div>
    </div>
  </div>

</div>

<script>

<?php
  if ('REX_VALUE[1]' == 'standart') {
    echo "$('.weitereeinstellungen').hide();";
  }
?>

$('#galerieart').change(function(){
  if(this.value == "fleximages") {
    $('.weitereeinstellungen').show();
  } else {
    $('.weitereeinstellungen').hide();
  }
});

</script>
<style>

#unite_gallery {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#unite_gallery h3.ueberschrift {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#unite_gallery .control-label {
  font-weight: normal;
  font-size: 12px !important;
}

#unite_gallery #anleitung {
  margin-top: 30px;
}

#unite_gallery #anleitung .control-label {
  margin-top: -7px;
}

#unite_gallery #anleitung .panel-heading {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  text-align: left;
  margin-bottom: 20px;
  border: none;
}
#unite_gallery #anleitung .panel-heading span {
  margin-right: 5px;
}
#unite_gallery #anleitung .panel-heading:hover  {
  color: #000;
}
</style>



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
  <div class="form-horizontal">
   <div class="form-group">
   <label class="col-sm-3 control-label" for="headline-level">Art der Galerie</label>
   <div class="col-sm-9">
     <?php
      $options = array(
       'columns'=>'Tiles - Columns',
       'justified'=>'Tiles - Justified',
       'nested'=>'Tiles - Nested',
       'grid'=>'Tiles Grid'
      );
      ?>
      <div class="rex-select-style">
      <select name="REX_INPUT_VALUE[1]" id="galerieart" class="form-control">
      <?php foreach ($options as $k=>$v) : ?>
      <option value="<?php echo $k; ?>"<?php if ($k == "REX_VALUE[1]") echo ' selected="selected"' ?>><?php echo $v; ?></option>
        <?php endforeach ?>
        </select>
      </div>
    </div>
  </div>

 <div class="form-group">
        <label class="col-sm-3 control-label">Breite der Galerie</label>
        <div class="col-sm-9 ">
          <div class="rex-select-style">
            <select id="glaeriebreite" name="REX_INPUT_VALUE[2]">
            <?php
              foreach (array('So breit wie der Inhalt','100% Browserbreite') as $value) {
                echo '<option value="'.$value.'" ';

                if ( "REX_VALUE[2]"=="$value" ) {
                  echo 'selected="selected" ';
                }
                echo '>'.$value.'</option>';
                }
            ?>
            </select>
          </div>
        </div>
      </div>

  <div class="form-group we_breite">
    <label class="col-sm-3 control-label">Breite der Bilder</label>
    <div class="col-sm-9">
      <input class="form-control" name="REX_INPUT_VALUE[3]" value="REX_VALUE[3]" type="text" />
    </div>
  </div>


  <div class="form-group we_hoehe">
    <label class="col-sm-3 control-label">Höhe der Bilder</label>
    <div class="col-sm-9">
      <input class="form-control" name="REX_INPUT_VALUE[4]" value="REX_VALUE[4]" type="text" />
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
      <label class="col-sm-3 control-label">Breite der Bilder</label>
        <div class="col-sm-9">
          <p>Aus dieser Angabe ergibt sich die Breite der Bilder. Sofern kein Wert angegeben wird wird eine Höhe von 200px benutzt.</p>
        </div>
    </div>


    <div class="form-group">
      <label class="col-sm-3 control-label">Höhe der Bilder</label>
        <div class="col-sm-9">
          <p>Aus dieser Angabe ergibt sich die Höhe der Bilder. Sofern kein Wert angegeben wird wird eine Höhe von 200px benutzt.</p>
        </div>
    </div>
</div>

<script>

<?php
  if ('REX_VALUE[1]' == 'columns' || 'REX_VALUE[1]' == 'nested') {
    echo "$('.we_breite').show();";
    echo "$('.we_hoehe').hide();";
  }
  if ('REX_VALUE[1]' == 'justified') {
    echo "$('.we_breite').hide();";
    echo "$('.we_hoehe').show();";
  }
  if ('REX_VALUE[1]' == 'grid') {
    echo "$('.we_breite').show();";
    echo "$('.we_hoehe').show();";
  }
?>

$('#galerieart').change(function(){
  if(this.value == "columns" || this.value == "nested" ) {
    $('.we_breite').show();
    $('.we_hoehe').hide();
  }

  if(this.value == "justified") {
    $('.we_breite').hide();
    $('.we_hoehe').show();
  }

  if(this.value == "grid") {
    $('.we_breite').show();
    $('.we_hoehe').show();
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



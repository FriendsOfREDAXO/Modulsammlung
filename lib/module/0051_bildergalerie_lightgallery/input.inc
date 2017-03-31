<!-- // --- MODUL | 03 . lightGalerie (INPUT) -->

<?php
//--- REX_VALUES
// settings
$value1 = rex_var::toArray('REX_VALUE[1]');
// data
$value2 = rex_var::toArray('REX_VALUE[2]');

// mediatyp
if ( !isset($value1['set_typ']) ) {
    // Ergänzungen benötigt für diverse Bildtypen im Mediamanager!
    $value1['set_typ'] = 'lightgallery_0450';
}

//--- REX_ADDONS
if( !rex_addon::get('lightgallery')->isAvailable() ) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "ligthgallery" Addon!');
}
if( !rex_addon::get('focuspoint')->isAvailable() ) {
    #echo rex_view::error('Dieses Modul ben&ouml;tigt das "ligthgallery" Addon!');
    $value1['set_focuspoint'] = true;
}
?>

<div class="ews__modul">

    <ul class="nav nav-tabs">
        <li class="active" id="col2__REX_SLICE_ID"><a data-toggle="tab" href="#value2__REX_SLICE_ID"><i></i><span>Galerie</span></a></li>

        <li class="pull-right"><a data-toggle="tab" href="#value1__REX_SLICE_ID"><i class="rex-icon rex-icon-metafuncs"></i><span> Weitere Einstellungen</span></a></li>
    </ul><!-- /.nav nav-tabs -->


    <div class="tab-content">

        <section id="value1__REX_SLICE_ID" class="tab-pane fade">

            <div class="panel-group" id="value1__REX_SLICE_ID__collapse__group1">

                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="#value1__REX_SLICE_ID__collapse__group1" data-target="#value1__REX_SLICE_ID__effects">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> Galerie-Effekte</i></div>
                    </header>

                    <div id="value1__REX_SLICE_ID__effects" class="panel-collapse collapse">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>Hover-Effekt</i>
                                <div class="col-sm-12">
                                    <?php
                                    $options = array(
                                        'effect--0'=>'Effektcode: 0',
                                        'effect--1'=>'Effektcode: 1',
                                        'effect--2'=>'Effektcode: 2',
                                        'effect--3'=>'Effektcode: 3',
                                        'effect--4'=>'Effektcode: 4',
                                        'effect--5'=>'Effektcode: 5',
                                        'effect--6'=>'Effektcode: 6',
                                        'effect--7'=>'Effektcode: 7',
                                        'effect--8'=>'Effektcode: 8',
                                        'effect--9'=>'Effektcode: 9',
                                        'effect--10'=>'Effektcode: 10',
                                        'effect--11'=>'Effektcode: 11',
                                        'effect--12'=>'Effektcode: 12',
                                        'effect--13'=>'Effektcode: 13',
                                        'effect--14'=>'Effektcode: 14'
                                    );
                                    ?>
                                    <select name="REX_INPUT_VALUE[1][set_effects]" id="grids" class="form-control">
                                        <?php foreach ($options as $k=>$v) : ?>
                                            <option value="<?php echo $k; ?>"<?php if ($k == $value1['set_effects']) echo ' selected="selected"' ?>><?php echo $v; ?></option>
                                        <?php endforeach ?>
                                    </select>
                                </div>
                            </div>

                            <div class="form-group">
                                <div class="col-sm-12">

                                    <div class="panel panel-default">
                                        <header class="panel-heading" data-toggle="collapse" data-parent="" data-target="#value2__REX_SLICE_ID__effects__info">
                                            <div class="panel-title"><i class="rex-icon rex-icon-info"> JS-Hinweis</i></div>
                                        </header>

                                        <div id="value2__REX_SLICE_ID__effects__info" class="panel-collapse collapse">
                                            <div class="panel-body">
                                                <ul>
                                                    <li>Benötigt die CSS-Effekte der Galerie!"</li>
                                                </ul>
                                            </div><!-- /.panel-body -->
                                        </div><!-- /.panel-collapse -->

                                    </div><!-- /.panel -->
                                </div>
                            </div>

                        </div><!-- /.panel-body -->
                    </div><!-- /.panel-collapse -->
                </div><!-- /.panel -->


                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="#value1__REX_SLICE_ID__collapse__group1" data-target="#value1__REX_SLICE_ID__animation">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> Animation</i></div>
                    </header>

                    <div id="value1__REX_SLICE_ID__animation" class="panel-collapse collapse">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>Animation</i>
                                <div class="col-sm-12">
                                    <?php
                                    $options = array(
                                        ''=>'Keine Animation',
                                        'fadeIn'=>'fadeIn',
                                        'fadeInDown'=>'fadeInDown',
                                        'fadeInDownBig'=>'fadeInDownBig',
                                        'fadeInLeft'=>'fadeInLeft',
                                        'fadeInLeftBig'=>'fadeInLeftBig',
                                        'fadeInRight'=>'fadeInRight',
                                        'fadeInRightBig'=>'fadeInRightBig',
                                        'fadeInUp'=>'fadeInUp',
                                        'fadeInUpBig'=>'fadeInUpBig'
                                    );
                                    ?>
                                    <select name="REX_INPUT_VALUE[1][set_animation]" id="animation" class="form-control">
                                        <?php foreach ($options as $k=>$v) : ?>
                                            <option value="<?php echo $k; ?>"<?php if ($k == $value1['set_animation']) echo ' selected="selected"' ?>><?php echo $v; ?></option>
                                        <?php endforeach ?>
                                    </select>
                                </div>
                            </div>

                            <div class="form-group">
                                <div class="col-sm-12">

                                    <div class="panel panel-default">
                                        <header class="panel-heading" data-toggle="collapse" data-parent="" data-target="#value1__REX_SLICE_ID__animation__info">
                                            <div class="panel-title"><i class="rex-icon rex-icon-info"> JS-Hinweis</i></div>
                                        </header>

                                        <div id="value1__REX_SLICE_ID__animation__info" class="panel-collapse collapse">
                                            <div class="panel-body">
                                                <ul>
                                                    <li>Benötigt die JavaScript-Datei "aniview.js" bzw. "aniview.min.js"</li>
                                                </ul>
                                            </div><!-- /.panel-body -->
                                        </div><!-- /.panel-collapse -->
                                    </div><!-- /.panel -->

                                </div>
                            </div>

                        </div><!-- /.panel-body -->

                    </div><!-- /.panel-collapse -->

                </div><!-- /.panel -->


                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="#value1__REX_SLICE_ID__collapse__group1" data-target="#value1__REX_SLICE_ID__hline">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> Trennlinie</i></div>
                    </header>

                    <div id="value1__REX_SLICE_ID__hline" class="panel-collapse collapse">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>Trennlinie</i>
                                <div class="col-sm-12">
                                    <?php
                                    $options = array(
                                        'horizontal__line'=>'Trennlinie: ja',
                                        ''=>'Trennlinie: nein'
                                    );
                                    ?>
                                    <select name="REX_INPUT_VALUE[1][set_hline]" id="hline" class="form-control">
                                        <?php foreach ($options as $k=>$v) : ?>
                                            <option value="<?php echo $k; ?>"<?php if ($k == $value1['set_hline']) echo ' selected="selected"' ?>><?php echo $v; ?></option>
                                        <?php endforeach ?>
                                    </select>
                                </div>
                            </div>
                        </div><!-- /.panel-body -->
                    </div><!-- /.panel-collapse -->
                </div><!-- /.panel -->


                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="#value1__REX_SLICE_ID__collapse__group1" data-target="#value1__REX_SLICE_ID__background">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> Hintergrund</i></div>
                    </header>

                    <div id="value1__REX_SLICE_ID__background" class="panel-collapse collapse">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>Hintergrund</i>
                                <div class="col-sm-12">
                                    <?php
                                    $options = array(
                                        'background--0'=>'Farbcode 0',
                                        'background--1'=>'Farbcode 1',
                                        'background--2'=>'Farbcode 2',
                                        'background--3'=>'Farbcode 3',
                                        'background--4'=>'Farbcode 4',
                                    );
                                    ?>
                                    <select name="REX_INPUT_VALUE[1][set_background]" id="line" class="form-control">
                                        <?php foreach ($options as $k=>$v) : ?>
                                            <option value="<?php echo $k; ?>"<?php if ($k == $value1['set_background']) echo ' selected="selected"' ?>><?php echo $v; ?></option>
                                        <?php endforeach ?>
                                    </select>
                                </div>
                            </div>

                        </div><!-- /.panel-body -->
                    </div><!-- /.panel-collapse -->
                </div><!-- /.panel -->


                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="#value1__REX_SLICE_ID__collapse__group1" data-target="#value1__REX_SLICE_ID__margin">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> Abstände</i></div>
                    </header>

                    <div id="value1__REX_SLICE_ID__margin" class="panel-collapse collapse">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>Vertikaler Abstand</i>
                                <div class="col-sm-12">
                                    <?php
                                    $options = array(
                                        'margin__top__bottom'=>'Vertikaler Abstand: ober- und unterhalb',
                                        'margin__top'=>'Vertikaler Abstand: oberhalb',
                                        'margin__bottom'=>'Vertikaler Abstand: unterhalb',
                                        ''=>'Vertikaler Abstand: keiner'
                                    );
                                    ?>
                                    <select name="REX_INPUT_VALUE[1][set_margin]" id="margin" class="form-control">
                                        <?php foreach ($options as $k=>$v) : ?>
                                            <option value="<?php echo $k; ?>"<?php if ($k == $value1['set_margin']) echo ' selected="selected"' ?>><?php echo $v; ?></option>
                                        <?php endforeach ?>
                                    </select>
                                </div>
                            </div>


                            <div class="form-group">
                                <i>Offset (nur wenn (volle Spalte gewählt)</i>
                                <div class="col-sm-12">
                                    <?php
                                    $options = array(
                                        'col-md-12 col-md-offset-0 col-sm-12 col-sm-offset-0 col-xs-12 col-xs-offset-0'=>'0 | Inhalt | 0',
                                        'col-md-10 col-md-offset-1 col-sm-10 col-sm-offset-1 col-xs-10 col-xs-offset-1'=>'1 | Inhalt | 1',
                                        'col-md-8 col-md-offset-2 col-sm-8 col-sm-offset-2 col-xs-8 col-xs-offset-2'=>'2 | Inhalt | 2'
                                    );
                                    ?>
                                    <select name="REX_INPUT_VALUE[1][set_offset]" id="offset" class="form-control">
                                        <?php foreach ($options as $k=>$v) : ?>
                                            <option value="<?php echo $k; ?>"<?php if ($k == $value1['set_offset']) echo ' selected="selected"' ?>><?php echo $v; ?></option>
                                        <?php endforeach ?>
                                    </select>
                                    <br>
                                    <p>Wählen Sie eine der nachfolgenden Optionen:</p>
                                    <ul>
                                        <li><strong>0 | Inhalt | 0</strong> => Abstand: 0 Spalten | Inhalt: 12 Spalten | Abstand: 0 Spalten</li>
                                        <li><strong>1 | Inhalt | 1</strong> => Abstand: 1 Spalten | Inhalt: 10 Spalten | Abstand: 1 Spalten</li>
                                        <li><strong>2 | Inhalt | 2</strong> => Abstand: 2 Spalten | Inhalt: 8 Spalten | Abstand: 2 Spalten</li>
                                    </ul>
                                </div>
                            </div>

                        </div><!-- /.panel-body -->
                    </div><!-- /.panel-collapse -->
                </div><!-- /.panel -->


                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="#value1__REX_SLICE_ID__collapse__group1" data-target="#value1__REX_SLICE_ID__typ">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> REX-Mediatyp</i></div>
                    </header>

                    <div id="value1__REX_SLICE_ID__typ" class="panel-collapse collapse">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>REX Mediatyp:</i>
                                <div class="col-sm-12">
                                    <input class="form-control" id="class" type="text" name="REX_INPUT_VALUE[1][set_typ]" value="<?php echo $value1['set_typ']; ?>" />
                                </div>
                            </div>

                        </div><!-- /.panel-body -->
                    </div><!-- /.panel-collapse -->
                </div><!-- /.panel -->


                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="#value1__REX_SLICE_ID__collapse__group1" data-target="#value1__REX_SLICE_ID__class">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> CSS-Klasse (gesamtes Modul)</i></div>
                    </header>

                    <div id="value1__REX_SLICE_ID__class" class="panel-collapse collapse">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>CSS (class):</i>
                                <div class="col-sm-12">
                                    <input class="form-control" id="class" type="text" name="REX_INPUT_VALUE[1][set_class]" value="<?php echo $value1['set_class']; ?>" />
                                </div>
                            </div>

                        </div><!-- /.panel-body -->
                    </div><!-- /.panel-collapse -->
                </div><!-- /.panel -->


            </div><!-- /.panel-group -->

        </section><!-- /.tab-pane -->


        <section id="value2__REX_SLICE_ID" class="tab-pane fade in active">

            <div class="panel-group" id="value2__REX_SLICE_ID__collapse__group1">

                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="" data-target="#value2__REX_SLICE_ID__text">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> Titel & Galerie</i></div>
                    </header>

                    <div id="value2__REX_SLICE_ID__text" class="panel-collapse collapse in">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>Titel:</i>
                                <div class="col-sm-12">
                                    <input class="form-control" id="headline1" type="text" name="REX_INPUT_VALUE[2][data_title]" value="<?php echo $value2['data_title']; ?>" />
                                </div>
                            </div>

                            <div class="form-group">
                                <i>Überschrift-Ebene</i>
                                <div class="col-sm-12">
                                    <?php
                                    $options = array(
                                        'h2'=>'2. Ebene',
                                        'h3'=>'3. Ebene'
                                    );
                                    ?>
                                    <select name="REX_INPUT_VALUE[2][data_hlevel]" id="headline-level1" class="form-control">
                                        <?php foreach ($options as $k=>$v) : ?>
                                            <option value="<?php echo $k; ?>"<?php if ($k == $value2['data_hlevel']) echo ' selected="selected"' ?>><?php echo $v; ?></option>
                                        <?php endforeach ?>
                                    </select>
                                </div>
                            </div>

                            <div class="form-group">
                                <i>Bilder</i>
                                <div class="col-sm-12">
                                    REX_MEDIALIST[id="1" widget="1"]
                                    <i>Bilder in der Medienkategorie "Fotos" (ID 1) haben ein zusätzliches Linkfeld.</i>
                                </div>
                            </div>

                        </div><!-- /.panel-body -->

                    </div><!-- /.panel-collapse -->

                </div><!-- /.panel -->

            </div><!-- /.panel-group -->


            <div class="panel-group" id="value2__REX_SLICE_ID__collapse__group2">

                <div class="panel panel-default">
                    <header class="panel-heading" data-toggle="collapse" data-parent="#value2__REX_SLICE_ID__collapse__group2" data-target="#value1__REX_SLICE_ID__frame">
                        <div class="panel-title"><i class="rex-icon rex-icon-metafuncs"> Bilder-Rahmen</i></div>
                    </header>

                    <div id="value1__REX_SLICE_ID__frame" class="panel-collapse collapse">
                        <div class="panel-body">

                            <div class="form-group">
                                <i>Rahmen</i>
                                <div class="col-sm-12">
                                    <?php
                                    $options = array(
                                        'gallery__item--framed'=>'Rahmen zwischen Bildern',
                                        'gallery__item--frameless'=>'ohne Rahmen'
                                    );
                                    ?>
                                    <select name="REX_INPUT_VALUE[2][data_frame]" id="frame" class="form-control">
                                        <?php foreach ($options as $k=>$v) : ?>
                                            <option value="<?php echo $k; ?>"<?php if ($k == $value2['data_frame']) echo ' selected="selected"' ?>><?php echo $v; ?></option>
                                        <?php endforeach ?>
                                    </select>
                                </div>
                            </div>

                        </div><!-- /.panel-body -->
                    </div><!-- /.panel-collapse -->
                </div><!-- /.panel -->

            </div><!-- /.panel-group -->

        </section><!-- /.tab-pane -->

    </div><!-- /.tab-content -->

</div><!-- /.ews__modul -->

<style>

    .ews__modul .panel-heading {
        font-size: 14px !important;
        padding: 10px;
        width: 100%;
        text-align: left;
        border: none;
    }
    .ews__modul .panel-heading span {
        margin-right: 5px;
    }

    .ews__modul .panel-heading:hover  {
        color: #000;
    }

    .ews__modul .panel-body {
        background: #FFF !important;
    }

    .ews__modul .nav-tabs>li>a {
        color: #31404F;
        background-color: #DFE3E9;
        border-top: 1px solid #9da6b2;
        border-left: 1px solid #9da6b2;
        border-right: 1px solid #9da6b2;
        padding: 8px;
        margin-bottom: 1px;
        height: 38px;
        top: 1px;
        padding-top: 10px;
    }

    .ews__modul .nav-tabs>li.active>a, .ews__modul .nav-tabs>li.active>a:hover, .ews__modul .nav-tabs>li.active>a:focus {
        color: #31404F;
        background-color: #f5f5f5;
        height: 39px;
    }

    .ews__modul .nav-tabs>li>a:hover {
        background-color: #fafafa;
        border-bottom: none;
    }

    .ews__modul .markitup {
        min-height: 200px;
    }

    .ews__modul .tab-content {
        background: #f5f5f5;
        margin-top: -20px;
        padding: 30px 15px;
        border-right: 1px solid #9da6b2;
        border-left: 1px solid #9da6b2;
        border-bottom: 1px solid #9da6b2;
    }

    .ews__modul .tab-content h3 {
        font-size: 14px !important;
        padding: 10px;
        background: #DFE3E9;
        width: 100%;
        margin-bottom: 20px;
    }

    .ews__modul .tab-content .control-label {
        font-weight: normal;
        /*font-size: 12px !important;*/
    }

    .ews__modul input.form-control,
    .ews__modul select.form-control,
    .ews__modul textarea.form-control {
        background: #fff !important;
    }

</style>
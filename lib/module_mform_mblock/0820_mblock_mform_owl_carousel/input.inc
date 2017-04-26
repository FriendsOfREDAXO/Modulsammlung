<?php

// this modul input uses the mform addon

echo '
<div id="owl_slider_module">
    <div id="tabs">
        <ul class="nav nav-tabs">
            <li class="locked pull-right"><a data-toggle="tab" href="#slideroptions"><i class="rex-icon rex-icon-system"></i> <span>Einstellungen</span></a></li>
            <li class="locked pull-right active"><a data-toggle="tab" href="#slides"><span>Slides</span></a></li>
        </ul>
    </div>'.PHP_EOL;

echo '    <div class="tab-content">'.PHP_EOL;
echo '        <div id="slides" class="tab-pane fade in active">'.PHP_EOL;

// base ID
$id = 1;

// init mform
$mform = new MForm();

// fieldset
$mform->addFieldset('<a class="expertOptions " data-toggle="collapse" data-target="#accordion%MB_COUNT%">Sliderbild</a>');

// media button
$mform->addMediaField(1, array('preview'=>'1'),'', array('label'=>'Medium'));

$mform->addHtml('<div class="collapse in" id="accordion%MB_COUNT%">');


// fieldset
$mform->addFieldset('Text Inputs');

// textarea
$mform->addTextAreaField("$id.0.slidertext", array('label'=>'Slidertext','class'=>'redactorEditor2-owlCarousel'));

// fieldset for positioning
$mform->addFieldset('Textplatzierung und Elemente');

// text placement
$mform->addSelectField("$id.0.textplace", array(0=>'nicht anzeigen','left-top'=>'links-oben','center-top'=>'mitte-oben','right-top'=>'rechts-oben','left-middle'=>'links-mitte','center-middle'=>'mitte-mitte','right-middle'=>'rechts-mitte','left-bottom'=>'links-unten','center-bottom'=>'mitte-unten','right-bottom'=>'rechts-unten'), array('label'=>'Textplatzierung'));

// special element
$mform->addSelectField("$id.0.element", array(0=>'nein',1=>'ja'), array('label'=>'Mit Element?'));

//ToDo
//add data-hash
$mform->addHtml('</div>');


// parse form
echo MBlock::show($id, $mform->show());
echo '        </div>'.PHP_EOL;
echo '        <div id="slideroptions" class="tab-pane fade in">'.PHP_EOL;
//base id options
$oid = 20;

// init options mform
$omform = new MForm();

// fieldset
$omform->addFieldset('Generelle Einstellungen');

// debug
$omform->addSelectField("$oid.0.debug", array('false'=>'Aus','true'=>'An'), array('label'=>'Debug <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Debug-Modus im BE an / aus."></i>'));

// layout
$omform->addSelectField("$oid.0.layout", array('wide'=>'100% Breite','boxed'=>'Boxed'), array('label'=>'Layout'));

//select option if image should be used in img tag
$omform->addSelectField("$oid.0.useImg", array('true'=>'Ja','false'=>'Nein'), array('label'=>'Bild als img ausgeben <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Nein - benötigt Lazyload auf Ja in den Experten-Einstellungen."></i>'));

// fieldset
$omform->addFieldset('Einstellungen OwlCarousel <small><a href="https://owlcarousel2.github.io/OwlCarousel2/docs/api-options.html" target="_blank">Offizielle Doku</a></small>');

// items
$omform->addInputField("number","$oid.0.items", array('label'=>'Items <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="The number of items you want to see on the screen. Default is 1"></i>'));

// loop
$omform->addSelectField("$oid.0.loop", array('true'=>'Ja','false'=>'Nein'), array('label'=>'Loop <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Infinity loop. Duplicate last and first items to get loop illusion."></i>'));

// nav
$omform->addSelectField("$oid.0.nav", array('false'=>'Nein','true'=>'Ja'), array('label'=>'nav <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Show next/prev buttons. Default: false"></i>'));

// dots
$omform->addSelectField("$oid.0.dots", array('true'=>'Ja','false'=>'Nein'), array('label'=>'dots <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Show dots navigation. Default: true"></i>'));

// autoplay
$omform->addSelectField("$oid.0.autoplay", array('false'=>'Nein','true'=>'Ja'), array('label'=>'autoplay <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Autoplay. Default: false"></i>'));

// autoplayTimeout
$omform->addInputField("number","$oid.0.autoplayTimeout", array('label'=>'autoplayTimeout <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Autoplay interval timeout. Default is 5000"></i>'));

// autoplayHoverPause
$omform->addSelectField("$oid.0.autoplayHoverPause", array('false'=>'Nein','true'=>'Ja'), array('label'=>'autoplayHoverPause <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Pause on mouse hover. Default: false"></i>'));

// margin
$omform->addInputField("number","$oid.0.margin", array('label'=>'Margin(px) <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="margin-right(px) on item. Default is 0"></i>'));

// fieldset
$omform->addFieldset('<a class="expertOptions" data-toggle="collapse" data-target="#expertOptions">Experten - Einstellungen OwlCarousel</a>');
// html
$omform->addHtml('<div class="collapse" id="expertOptions">');
// rewind
$omform->addSelectField("$oid.0.rewind", array('true'=>'Ja','false'=>'Nein'), array('label'=>'rewind <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Go backwards when the boundary has reached. Default: true"></i>'));

// center
$omform->addSelectField("$oid.0.center", array('false'=>'Nein','true'=>'Ja'), array('label'=>'Center <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Center item. Works well with even an odd number of items."></i>'));

// mouseDrag
$omform->addSelectField("$oid.0.mouseDrag", array('true'=>'Ja','false'=>'Nein'), array('label'=>'mouseDrag <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Mouse drag enabled."></i>'));

// touchDrag
$omform->addSelectField("$oid.0.touchDrag", array('true'=>'Ja','false'=>'Nein'), array('label'=>'touchDrag <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Touch drag enabled."></i>'));

// pullDrag
$omform->addSelectField("$oid.0.pullDrag", array('true'=>'Ja','false'=>'Nein'), array('label'=>'pullDrag <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Stage pull to edge."></i>'));

// freeDrag
$omform->addSelectField("$oid.0.freeDrag", array('false'=>'Nein','true'=>'Ja'), array('label'=>'freeDrag <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Item pull to edge."></i>'));

// stagePadding
$omform->addInputField("number","$oid.0.stagePadding", array('label'=>'stagePadding <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Padding left and right on stage (can see neighbours). Default is 0"></i>'));

// autowidth
$omform->addSelectField("$oid.0.autowidth", array('true'=>'Ja','false'=>'Nein'), array('label'=>'autowidth <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Set non grid content. Try using width style on divs."></i>'));

// startPosition
$omform->addTextField("$oid.0.startPosition", array('label'=>'startPosition <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Start position or URL Hash string like \'#id\'."></i>'));

// URLhashListener
$omform->addSelectField("$oid.0.URLhashListener", array('false'=>'Nein','true'=>'Ja'), array('label'=>'URLhashListener <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Listen to url hash changes. data-hash on items is required."></i>'));

// navText
$omform->addTextField("$oid.0.navText", array('label'=>'navText <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: Array. HTML allowed. Default: &#x27;next&#x27;,&#x27;prev&#x27;"></i>'));

// navElement
$omform->addTextField("$oid.0.navElement", array('label'=>'navElement <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: String. DOM element type for a single directional navigation link. Default: div"></i>'));

// slideBy
$omform->addTextField("$oid.0.slideBy", array('label'=>'slideBy <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: Number/String. Navigation slide by x. \'page\' string can be set to slide by page. Default: 1"></i>'));

// dotsEach
$omform->addSelectField("$oid.0.dotsEach", array('false'=>'Nein','true'=>'Ja'), array('label'=>'dotsEach <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Show dots each x item. Default: false"></i>'));

// lazyLoad
$omform->addSelectField("$oid.0.lazyLoad", array('false'=>'Nein','true'=>'Ja'), array('label'=>'lazyLoad <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Lazy load images. data-src and data-src-retina for highres. Also load images into background inline style if element is not <img> Default: false"></i>'));

// lazyContent - commented out since not implemented yet implemented in Owl Carousel
//$omform->addSelectField("$oid.0.lazyContent", array('false'=>'Nein','true'=>'Ja'), array('label'=>'lazyContent <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Lazy load images. data-src and data-src-retina for highres. Also load images into background inline style if element is not <img> Default: false"></i>'));

// responsiveClass
$omform->addSelectField("$oid.0.responsiveClass", array('true'=>'Ja','false'=>'Nein'), array('label'=>'responsiveClass <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Can be set to false to remove responsive capabilities. Default: true"></i>'));

// responsive
$omform->addTextAreaField("$oid.0.responsive", array('label'=>'responsive <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: Object containing responsive options."></i>'));

// responsiveRefreshRate
$omform->addInputField("number","$oid.0.responsiveRefreshRate", array('label'=>'responsiveRefreshRate <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Responsive refresh rate. Default: 200"></i>'));

// responsiveBaseElement
$omform->addTextField("$oid.0.responsiveBaseElement", array('label'=>'responsiveBaseElement <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Set on any DOM element. If you care about non responsive browser (like ie8) then use it on main wrapper. This will prevent from crazy resizing. Default: window"></i>'));

// video
$omform->addSelectField("$oid.0.video", array('false'=>'Nein','true'=>'Ja'), array('label'=>'video <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Enable fetching YouTube/Vimeo/Vzaar videos. Default: false"></i>'));

// videoHeight
$omform->addTextField("$oid.0.videoHeight", array('label'=>'videoHeight <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: Number/Boolen. Set height for videos. Default: false"></i>'));

// videoWidth
$omform->addTextField("$oid.0.videoWidth", array('label'=>'videoWidth <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: Number/Boolen. Set width for videos. Default: false"></i>'));

// animationOut
$omform->addTextField("$oid.0.animationOut", array('label'=>'animationOut <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: String/Boolen. Class for CSS3 animation out. Default: false"></i>'));

// animationInClass
$omform->addTextField("$oid.0.animationInClass", array('label'=>'animationInClass <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: String/Boolen. Class for CSS3 animation in. Default: false"></i>'));

// nestedItemSelector
$omform->addTextField("$oid.0.nestedItemSelector", array('label'=>'nestedItemSelector <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: String/Class. Use it if owl items are deep nested inside some generated content. E.g \'youritem\'. Dont use dot before class name. Default: false"></i>'));

// itemElement
$omform->addTextField("$oid.0.itemElement", array('label'=>'itemElement <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="DOM element type for owl-item. Default: div"></i>'));

// stageElement
$omform->addTextField("$oid.0.stageElement", array('label'=>'stageElement <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="DOM element type for owl-stage. Default: div"></i>'));

// navContainer
$omform->addTextField("$oid.0.navContainer", array('label'=>'navContainer <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: String/Class/ID/Boolean. Set your own container for nav. Default: false"></i>'));

// dotsContainer
$omform->addTextField("$oid.0.dotsContainer", array('label'=>'dotsContainer <i class="rex-icon fa-info-circle" data-toggle="tooltip" data-placement="top" title="Type: String/Class/ID/Boolean. Set your own container for dotsNav. Default: false"></i>'));
// html
$omform->addHtml('</div>');

// fieldset
$omform->addFieldset('CSS und ID setzen um den OwlSlider');

// itemElement
$omform->addTextField("$oid.0.cssclasses", array('label'=>'Klassen'));

// itemElement
$omform->addTextField("$oid.0.cssid", array('label'=>'ID'));


echo $omform->show();

echo '        </div>
    </div>
</div>'.PHP_EOL;

?>

<script>
    $(function () {
        $('[data-toggle="tooltip"]').tooltip()
    })
</script>

<style>
    #owl_slider_module #tabs i {
    //display: none;
    }

    #owl_slider_module #tabs span {
        display: inline-block;
    }

    #owl_slider_module .expertOptions {
        cursor: pointer;
        color: #000;
    }
    #owl_slider_module .expertOptions:hover,
    #owl_slider_module .expertOptions:focus,
    #owl_slider_module .expertOptions:active
    {
        color: #666;
        text-decoration: none;
    }

    @media (max-width:767px) {
        #owl_slider_module #tabs i {
            display: inline-block;
            font-style: normal;
            padding: 0 5px 0 5px;
            font-size: 16px;
        }
        #owl_slider_module #tabs span {
            display: none;
        }
        #owl_slider_module .control-label {
            margin-left: 10px;
        }

        #owl_slider_module #anleitung p {
            padding-left: 20px;
        }

        #owl_slider_module #anleitung .control-label {
            padding-left: 25px;
        }

    }

    #owl_slider_module #anleitung .control-label {
        margin-top: -6px;
    }


    #owl_slider_module #anleitung {
        margin-top: 20px;
    }

    #owl_slider_module #anleitung .panel-heading {
        font-size: 14px !important;
        padding: 10px;
        background: #DFE3E9;
        width: 100%;
        text-align: left;
        margin-bottom: 20px;
        border: none;
    }
    #owl_slider_module #anleitung .panel-heading span {
        margin-right: 5px;
    }

    #owl_slider_module #anleitung .panel-heading:hover  {
        color: #000;
    }

    #owl_slider_module .nav-tabs>li>a {
        color: #31404F;
        background-color: #DFE3E9;
        font-size: 12px;
        border-top: 1px solid #9da6b2;
        border-left: 1px solid #9da6b2;
        border-right: 1px solid #9da6b2;
        padding: 8px;
        margin-bottom: 1px;
        height: 38px;
        top: 1px;
        padding-top: 10px;
    }

    #owl_slider_module .nav-tabs>li.active>a, #owl_slider_module .nav-tabs>li.active>a:hover, #owl_slider_module .nav-tabs>li.active>a:focus {
        color: #31404F;
        background-color: #f5f5f5;
        height: 39px;
    }

    #owl_slider_module .ui-sortable-helper {}

    #owl_slider_module .nav-tabs>li>a:hover {
        background-color: #fafafa;
        border-bottom: none;
    }

    #owl_slider_module .markitup {
        min-height: 200px;
    }


    #owl_slider_module .tab-content {
        background: #f5f5f5;
        margin-top: -20px;
        padding: 10px;
        border-right: 1px solid #9da6b2;
        border-left: 1px solid #9da6b2;
        border-bottom: 1px solid #9da6b2;
    }

    #owl_slider_module .tab-content h3 {
        font-size: 14px !important;
        padding: 10px;
        background: #DFE3E9;
        width: 100%;
        margin-bottom: 20px;
    }
</style>

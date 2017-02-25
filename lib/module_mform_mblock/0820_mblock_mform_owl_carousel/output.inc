<?php

//get config
$owlConfiguration = rex_var::toArray("REX_VALUE[20]");

//fetch items
$items = rex_var::toArray("REX_VALUE[1]");

if(rex::isBackend()) {
    //get core version
    $coreVersion = rex_config::get('core','version');
    //show debug
    if($owlConfiguration[0]['debug'] == 'true') {
        if($coreVersion < '5.3.0') {
            echo '<pre>';
            print_r(rex_var::toArray("REX_VALUE[1]"));
            print_r(rex_var::toArray("REX_VALUE[20]"));
            echo '</pre>';
        }
        else {
            echo '<pre>';
            dump(rex_var::toArray("REX_VALUE[1]"));
            dump(rex_var::toArray("REX_VALUE[20]"));
            echo '</pre>';
        }
    }

    //show what was edited
    $output = '';

    $output .= '<strong>Layout:</strong> '.$owlConfiguration[0]['layout'] . '<hr />';

    foreach($items as $item) {
        //get media item
        $file = rex_media::get($item['REX_INPUT_MEDIA_1']);
        $mediaPath = $file->getUrl();
        $mediaTitle = $file->getTitle();

        $output .= '        <div class="row">';
        $output .= '            <div class="col-sm-4">';
        $output .= '            <img class="img-responsive" src="index.php?rex_media_type=owlCarousel_backend&amp;rex_media_file=' . $item['REX_INPUT_MEDIA_1'] . '" alt="' . $mediaTitle . '">';
        $output .= '            </div>';
        $output .= '            <div class="col-sm-5">';
        $output .= '                <strong>Text:</strong><br>' . $item['slidertext'];
        $output .= '            </div>';
        $output .= '            <div class="col-sm-3">';
        $output .= '                <strong>Ausrichtung:</strong><br> '. ($item['textplace'] != '0' ? $item['textplace'] : '');
        $output .= '            </div>';
        $output .= '        </div>';
        $output .= '<hr />';
    }

    print $output;
}
else {
    $output = '';

    //layout config
    if($owlConfiguration[0]['layout'] == 'boxed') {
        $output .= '<div class="container">'.PHP_EOL;
        $output .= '    <div class="row">'.PHP_EOL;
        $output .= '        <div class="col-sm-12">'.PHP_EOL;
    }

    // surrounding container
    $output .= '<div'.(!empty($owlConfiguration[0]['cssid']) ? ' id="' . $owlConfiguration[0]['cssid'] . '"' : '').(!empty($owlConfiguration[0]['cssclasses']) ? ' class="' . $owlConfiguration[0]['cssclasses'] . '"' : '').'>';
    $output .= '<div id="carousel-REX_SLICE_ID" class="owl-carousel">';

    foreach($items as $item) {
        //get media item
        $file = rex_media::get($item['REX_INPUT_MEDIA_1']);
        $mediaPath = $file->getUrl();
        $mediaTitle = $file->getTitle();

        // Todo:implement data-hashes

        $output .= '        <div class="item'.($owlConfiguration[0]['lazyLoad'] == 'true' && $owlConfiguration[0]['useImg'] == 'false' ? ' lazyload" data-src="index.php?rex_media_type=owlCarousel_content&amp;rex_media_file=' . $item['REX_INPUT_MEDIA_1'] . '"  data-src-retina="index.php?rex_media_type=owlCarousel_content_retina&amp;rex_media_file=' . $item['REX_INPUT_MEDIA_1'] . '"' : '"').'>';
        $output .= ($owlConfiguration[0]['useImg'] == 'true' ? '            <img'.($owlConfiguration[0]['lazyLoad'] == 'true' ? ' class="lazyload" data-src="index.php?rex_media_type=owlCarousel_content&amp;rex_media_file=' . $item['REX_INPUT_MEDIA_1'] . '"  data-src-retina="index.php?rex_media_type=owlCarousel_content_retina&amp;rex_media_file=' . $item['REX_INPUT_MEDIA_1'] . '"' : '').' src="index.php?rex_media_type=owlCarousel_content&amp;rex_media_file=' . $item['REX_INPUT_MEDIA_1'] . '" alt="' . $mediaTitle . '">' : '');
        $output .= '            <div class="container">';
        $output .= '                <div class="carousel-caption">';
        $output .= '                    '.($item['element'] != 0 ? '<div class="svg-circle"></div>' : '');
        $output .= '                    <div class="' . ($item['textplace'] != '0' ? $item['textplace'] : '') . '">' . $item['slidertext'] . '</div>';
        $output .= '                </div>';
        $output .= '            </div>';
        $output .= '        </div>';
    }
    $output .= '</div>';

    //layout config
    if($owlConfiguration[0]['layout'] == 'boxed') {
        $output .= '        </div>'.PHP_EOL;
        $output .= '    </div>'.PHP_EOL;
        $output .= '</div>'.PHP_EOL;
    }
    $output .= '</div>'.PHP_EOL;

    //let the owls have it
    print $output;

}

?>

<?php if (!rex::isBackend()): ?>
    <script>
        //Uncomment the next line if you want to use jQuery in the footer: https://gist.github.com/elricco/a2bddb994a7a21152c65743829a2ebce
        //elricco.funcs.push(function () {
        //comment the next line out if you want to use jQuery in the footer
        $(function () {
            // hier dein Code, jQuery/$ ist verfügbar
            $("#carousel-REX_SLICE_ID").owlCarousel({
                <?php echo ($owlConfiguration[0]['margin'] == '' ? '' : 'margin: ' . $owlConfiguration[0]['margin']).PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['loop'] == 'true' ? 'loop: true,' : 'loop: ' . $owlConfiguration[0]['loop'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['center'] == 'false' ? '' : 'center: ' . $owlConfiguration[0]['center'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['mouseDrag'] == 'true' ? '' : 'mouseDrag: ' . $owlConfiguration[0]['mouseDrag'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['touchDrag'] == 'true' ? '' : 'touchDrag: ' . $owlConfiguration[0]['touchDrag'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['pullDrag'] == 'true' ? '' : 'pullDrag: ' . $owlConfiguration[0]['pullDrag'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['freeDrag'] == 'false' ? '' : 'freeDrag: ' . $owlConfiguration[0]['freeDrag'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['stagePadding'] == '' ? '' : 'stagePadding: ' . $owlConfiguration[0]['stagePadding']).PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['autoWidth'] == '' ? '' : 'autoWidth: ' . $owlConfiguration[0]['autoWidth'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['startPosition'] == '' ? '' : 'startPosition: ' . $owlConfiguration[0]['startPosition']).PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['URLhashListener'] == 'false' ? '' : 'URLhashListener: ' . $owlConfiguration[0]['URLhashListener']).PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['nav'] == 'false' ? '' : 'nav: ' . $owlConfiguration[0]['nav'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['rewind'] == 'true' ? '' : 'rewind: ' . $owlConfiguration[0]['rewind'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['navText'] == '' ? '' : 'navText: [' . $owlConfiguration[0]['navText'] . ']').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['navElement'] == '' ? '' : 'navElement: \'' . $owlConfiguration[0]['navElement'] . '\'').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['slideBy'] == '' ? '' : 'slideBy: \'' . $owlConfiguration[0]['slideBy'] . '\'').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['dots'] == 'false' ? '' : 'dots: ' . $owlConfiguration[0]['dots'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['dotsEach'] == 'false' ? '' : 'dotsEach: ' . $owlConfiguration[0]['dotsEach'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['lazyLoad'] == 'false' ? '' : 'lazyLoad: ' . $owlConfiguration[0]['lazyLoad'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['autoplay'] == 'false' ? '' : 'autoplay: ' . $owlConfiguration[0]['autoplay'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['autoplayTimeout'] == '' ? '' : 'autoplayTimeout: ' . $owlConfiguration[0]['autoplayTimeout'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['autoplayHoverPause'] == 'false' ? '' : 'autoplayHoverPause: ' . $owlConfiguration[0]['autoplayHoverPause'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['responsiveClass'] == 'true' ? 'responsiveClass: true,' : 'responsiveClass: ' . $owlConfiguration[0]['responsiveClass'] . ',').PHP_EOL; ?>
                <?php echo (($owlConfiguration[0]['responsiveClass'] == 'true' && $owlConfiguration[0]['responsive']) != '' ? $owlConfiguration[0]['responsive'] . ',' : '').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['responsiveRefreshRate'] == '' ? '' : 'responsiveRefreshRate: ' . $owlConfiguration[0]['responsiveClass'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['responsiveRefrveBaseElement'] == '' ? '' : 'responsiveBaseElement: ' . $owlConfiguration[0]['responsiveBaseElement'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['video'] == 'false' ? '' : 'video: ' . $owlConfiguration[0]['video'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['videoHeight'] == '' ? '' : 'videoHeight: ' . $owlConfiguration[0]['videoHeight'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['videoWidth'] == '' ? '' : 'videoWidth: ' . $owlConfiguration[0]['videoWidth'] . ',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['animateOut'] == '' ? '' : 'animateOut: \'' . $owlConfiguration[0]['animateOut'] . '\',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['animateInClass'] == '' ? '' : 'animateInClass: \'' . $owlConfiguration[0]['animateInClass'] . '\',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['nestedItemSelector'] == '' ? '' : 'nestedItemSelector: \'' . $owlConfiguration[0]['nestedItemSelector'] . '\',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['itemElement'] == '' ? '' : 'itemElement: \'' . $owlConfiguration[0]['itemElement'] . '\',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['stageElement'] == '' ? '' : 'stageElement: \'' . $owlConfiguration[0]['stageElement'] . '\',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['navContainer'] == '' ? '' : 'navContainer: \'' . $owlConfiguration[0]['navContainer'] . '\',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['dotsContainer'] == '' ? '' : 'dotsContainer: \'' . $owlConfiguration[0]['dotsContainer'] . '\',').PHP_EOL; ?>
                <?php echo ($owlConfiguration[0]['items'] == '' ? 'items: 1' : 'items: ' . $owlConfiguration[0]['items']).PHP_EOL; ?>
            });
        });
    </script>
<?php endif; ?>
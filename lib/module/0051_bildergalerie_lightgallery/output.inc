<!-- // --- MODUL | 03 . Galerie (OUTPUT) -->

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

// animation
if ( !isset($value1['set_animationclass']) ) {
    $value1['set_animationclass'] = 'aniview';
}

// values
$value1['set_template'] = ($this->getTemplateId() == 3) ? ' container' : '';
$value1['set_margin'] = ($value1['set_margin'] != '') ? ' '.$value1['set_margin'] : '';

//--- PRESETS
// Rahmen?
$value2['data_frame'] = ($value2['data_frame'] != '') ? $value2['data_frame'] : 'gallery__item--framed';

// Language suffix
$languageSuffix = '';
$languageSuffix = (rex_clang::getCurrentId() == 2) ? '_en' : '';

// frontend / backend
$frontend = '';
$backend = '';

if ("REX_MEDIALIST[1]" != '') {
    $media_list = explode(',', "REX_MEDIALIST[1]");

    $frontend .= '
	<section class="gallery__wrapper clearfix '.$value1['set_background'].' '.$value1['set_class'].'">';

    $frontend .= '
        <div class="gallery '.$value1['set_template'].' '.$value1['set_margin'].'">';

    if ($value2['data_title'] != '') {
        $frontend .= '
			<'.$value2['data_hlevel'].'>'.$value2['data_title'].'</'.$value2['data_hlevel'].'>';
        $backend .= '
			<'.$value2['data_hlevel'].'>'.$value2['data_title'].'</'.$value2['data_hlevel'].'>';
    }

    $frontend .= '
		    <div class="row">';

    //Zaehler fuer DIVs
    $i = 1;

    foreach ($media_list as $media_file) {
        $media = rex_media::get($media_file);
        if ($media) {

            $media_title = $media->getTitle('title' );
            $media_title_blanc = ( $media_title != '') ? $media_title : '';
            $media_title = ( $media_title != '') ? 'TITLE: ' .$media_title : 'TITLE: -';
            $media_description = str_replace(array("\r\n", "\n", "\r"), ' ', $media->getValue('med_description'.$languageSuffix));
            $media_description_blanc = ( $media_description != '' ) ? ' '.$media_description : '';
            $media_description = ( $media_description != '' ) ? 'DESCRIPTION: '.$media_description : 'DESCRIPTION: -';
            $media_copyright = $media->getValue('med_copyright');
            $media_copyright = ( $media_copyright != '' ) ? 'AUTOR: '.$media_copyright : 'AUTOR: -';
            $media_link = $media->getValue('med_gallery_link');
            $media_link = ( $media_link != '' ) ? $media_link : '';

            $frontend .= '
            <div class="gallery__item '.$value2['data_frame'].' col-md-3 col-sm-4 col-xs-6 '.$value1['set_animationclass'].'" data-av-animation="'.$value1['set_animation'].'">
            
                <figure class="'.$value1['set_effects'].'">
                    <img src="index.php?rex_media_type='.$value1['set_typ'].'&rex_media_file='.$media_file.'" 
                        srcset="" 
                        title="'.$media_copyright.' | '.$media_title.' | '.$media_description.'" 
                        alt="'.$media_copyright.' | '.$media_title.' | '.$media_description.'
                        ">
                    <figcaption>';

            #if ( $media_description != '' && $this->getTemplateId() == 3 ) {
            if ( $media_description != '' ) {
                // Nur im Einspalter "02 . Article (1-col)" Bildtexte anzeigen, da Bilder ansonsten zu klein
                $frontend .= '
                        <h2><span>'.$media_title_blanc.'</span></h2>
                        <p>'.$media_description_blanc.'</p>';
            }

            $frontend .= '
                        <a class="lightgallery__button" rel="lg__REX_SLICE_ID" data-src="index.php?rex_media_type=lightgallery_1100&rex_media_file='.$media_file.'">
                            <img src="index.php?rex_media_type='.$value1['set_typ'].'&rex_media_file='.$media_file.'" title="'.$media_copyright.' | '.$media_title.' | '.$media_description.'" alt="'.$media_copyright.' | '.$media_title.' | '.$media_description.'">
                        </a>';

            if ($media_link != '') {
                $frontend .= '
                        <a href="'.$media_link.'"></a>';
            }

            $frontend .= '
                    </figcaption>			
                </figure>
                
            </div><!-- /.gallery__item  -->';

            $backend .= '
            <img src="index.php?rex_media_type=rex_mediapool_detail&rex_media_file='.$media_file.'" title="'.$media_copyright.' | '.$media_title.' | '.$media_description.'" alt="'.$media_copyright.' | '.$media_title.' | '.$media_description.'">';

        }
    }

    $frontend .= '
            </div><!-- /.row -->
            
            <div class="'.$value1['set_hline'].'"></div>

		</div><!-- /.gallery -->
		
	</section><!-- /.gallery__wrapper clearfix -->';

}

// Different output for frontend and backend
if (rex::isBackend()) {
    echo $backend;
} else {
    echo $frontend;
}

if ( rex::isBackend() && $value1['set_class'] != '' ) {
    echo '<i>Zusätzliche CSS-KLASSE: ' .$value1['set_class']. '</i>';
}
?>
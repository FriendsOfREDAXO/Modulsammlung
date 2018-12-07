<?php
if(!function_exists('processURL')) {
	function processURL($url)
	{
		$ch = curl_init();
		curl_setopt_array($ch, array(
			CURLOPT_URL => $url,
			CURLOPT_RETURNTRANSFER => true,
			CURLOPT_SSL_VERIFYPEER => false,
			CURLOPT_SSL_VERIFYHOST => 2
		));
		
		$result = curl_exec($ch);
		curl_close($ch);
		return $result;
	}
}

$client_id    = "REX_VALUE[id=1]";
$access_token = 'REX_VALUE[id=2]';
$url          = 'https://api.instagram.com/v1/users/self/media/recent/?client_id=' . $client_id . '&access_token=' . $access_token;

$all_result      = processURL($url);
$decoded_results = json_decode($all_result, true);

$images = array();

foreach ($decoded_results['data'] as $item) {
    
    $instaname 		= $item['user']['username'];
    $image_thumb 	= $item['images']['thumbnail']['url']; 				// URL zum Thumbnail
	$image_standard = $item['images']['standard_resolution']['url']; 	// URL zur Standardaufloesung
    $image_big  	= $item['images']['standard_resolution']['url']; 	// URL zur grossen Version 
    $caption    	= $item['caption']['text']; 						// Beschreibung
 
    echo '<figure>
              <img src="' . $image_thumb . '" alt="' . $instaname . '" >
		      <figcaption>' . $caption . '</figcaption>
		  </figure>';
}
?>
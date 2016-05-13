<?php

 $template = rex_sql::factory();


 $template = rex_sql::factory();
 $template->setTable('rex_template');
 $template->setValue('name', '0500 - Download Hilfstemplate');
 $template->setValue('active', '1');
 $template->setValue('content', '<?php
$file_name = strtolower(preg_replace("/[^a-zA-Z0-9.\-\$\+]/","_",rex_request("file", "string")));
$file_type = "application/octetstream";
$file_path = rex_path::media($file_name);

if ($file_name != "" && $fp = @fopen("$file_path", "r"))
{

  header("Expires: Mon, 01 Jan 2000 01:01:01 GMT"); // Date in the past
  header("Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT");// always modified
  header("Cache-Control: no-store, no-cache, must-revalidate");// HTTP/1.1
  header("Cache-Control: post-check=0, pre-check=0", false);
  header("Cache-Control: private");
  header("Pragma: no-cache");
  header("Content-Type: $file_type; name=\"$file_name\"");
  header("Content-Disposition: attachment; filename=\"$file_name\"");

  fpassthru ($fp);
  fclose($fp);
  exit;

} else {

echo "<div class=warning>Download fehlgeschlagen</div>";

}
?>');
 $template->setValue('attributes', '{"ctype":[],"modules":{"1":{"all":0}},"categories":{"all":"1"}}');

  try {
    $template->insert();
    echo rex_view::success('Das Template "0500 - Download Hilfstemplate" wurde angelegt und kann verwendet werden.!');
  } catch (rex_sql_exception $e) {
    echo rex_view::warning('Das Template "0500 - Download Hilfstemplate" konnte nicht angelegt werden.');
  }

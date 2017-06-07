<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1">

	<title><?php echo htmlspecialchars($this->getValue('name')); ?></title>

	<!-- Load Bootstrap core CSS -->
	<link href="https://getbootstrap.com/dist/css/bootstrap.min.css" rel="stylesheet">
</head>

<body>

<div class="container">

	<div class="header clearfix">
		<nav>
			<ul class="nav nav-pills pull-right">
				<?php
				foreach (rex_category::getRootCategories(true) as $item) {
					echo '<li><a href="'.$item->getUrl().'">'.htmlspecialchars($item->getValue('name')).'</a></li>';
				}
				?>
			</ul>
		</nav>
		<h3 class="text-muted"><?php echo rex::getServerName(); ?></h3>
	</div>

	REX_ARTICLE[]

	<footer class="footer">
		<p>&copy; <?php echo date("Y").' '.rex::getServerName(); ?></p>
	</footer>

</div> <!-- /container -->

</body>
</html>
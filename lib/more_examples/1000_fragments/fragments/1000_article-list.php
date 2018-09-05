<ul>
<?php foreach ($this->getVar('elements') as $element): ?>
    <li><a href="<?= $element['url'] ?>"><?= $element['label'] ?></a></li>
<?php endforeach; ?>
</ul>
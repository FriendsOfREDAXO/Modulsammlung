<div class="list-group">
<?php foreach ($this->getVar('elements') as $element): ?>
    <a class="list-group-item list-group-item-action" href="<?= $element['url'] ?>"><?= $element['label'] ?></a>
<?php endforeach; ?>
</div>
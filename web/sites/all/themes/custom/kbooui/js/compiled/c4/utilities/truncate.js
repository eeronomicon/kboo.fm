// Generated by CoffeeScript 1.10.0
(function() {
  (function($) {
    return C4.Utilities.Truncate = (function() {
      function Truncate() {}

      Truncate.truncated_elements = ".truncate";

      Truncate.truncate = function($parent) {
        var $collection;
        if (typeof $parent === 'undefined') {
          $parent = $(document);
        }
        $collection = $parent.find(Truncate.truncated_elements);
        return $collection.each(Truncate.truncateElement);
      };

      Truncate.truncateElement = function(index, element) {
        var $element, lines;
        $element = $(element);
        lines = 1;
        if ($element.data('truncate-lines') != null) {
          lines = $element.data('truncate-lines');
        }
        $element.trunk8({
          lines: lines
        });
        return true;
      };

      return Truncate;

    })();
  })(jQuery);

}).call(this);

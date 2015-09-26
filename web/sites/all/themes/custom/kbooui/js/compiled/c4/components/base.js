// Generated by CoffeeScript 1.9.3
(function() {
  (function($) {
    return C4.Components.Base = (function() {
      function Base() {
        this.init();
        this.bind();
      }

      Base.prototype.init = function() {
        this.$document = $(document);
        return true;
      };

      Base.prototype.bind = function() {
        return true;
      };

      Base.prototype.addItem = function(event, selector, callback) {
        return this.bindItem(event, selector, callback, true);
      };

      Base.prototype.bindItem = function(event, selector, callback, ignoreOff) {
        if (ignoreOff == null) {
          ignoreOff = false;
        }
        if (callback == null) {
          callback = selector;
          if (!ignoreOff) {
            this.$document.off(event);
          }
          return this.$document.on(event, callback);
        } else {
          if (!ignoreOff) {
            this.$document.off(event, selector);
          }
          return this.$document.on(event, selector, callback);
        }
      };

      Base.prototype.bindToObject = function(event, $object, callback, ignoreOff) {
        if (ignoreOff == null) {
          ignoreOff = false;
        }
        if (!ignoreOff) {
          $object.off(event);
        }
        return $object.on(event, callback);
      };

      return Base;

    })();
  })(jQuery);

}).call(this);

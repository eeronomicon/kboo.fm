// Generated by CoffeeScript 1.10.0
(function() {
  var bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; },
    extend = function(child, parent) { for (var key in parent) { if (hasProp.call(parent, key)) child[key] = parent[key]; } function ctor() { this.constructor = child; } ctor.prototype = parent.prototype; child.prototype = new ctor(); child.__super__ = parent.prototype; return child; },
    hasProp = {}.hasOwnProperty;

  (function($) {
    return C4.Components.Dropdown = (function(superClass) {
      extend(Dropdown, superClass);

      function Dropdown() {
        this.dropdownShown = bind(this.dropdownShown, this);
        return Dropdown.__super__.constructor.apply(this, arguments);
      }

      Dropdown.prototype.dropdown = ".c4-dropdown";

      Dropdown.prototype.bind = function() {
        this.bindItem("shown.bs.dropdown", this.dropdown, this.dropdownShown);
        return true;
      };

      Dropdown.prototype.dropdownShown = function(event) {
        C4.Utilities.Truncate.truncate($(event.target));
        return true;
      };

      return Dropdown;

    })(C4.Components.Base);
  })(jQuery);

}).call(this);

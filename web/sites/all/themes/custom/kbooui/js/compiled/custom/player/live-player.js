// Generated by CoffeeScript 1.10.0
(function() {
  var bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; },
    extend = function(child, parent) { for (var key in parent) { if (hasProp.call(parent, key)) child[key] = parent[key]; } function ctor() { this.constructor = child; } ctor.prototype = parent.prototype; child.prototype = new ctor(); child.__super__ = parent.prototype; return child; },
    hasProp = {}.hasOwnProperty,
    modulo = function(a, b) { return (+a % (b = +b) + b) % b; };

  (function($) {
    App.Player.Live = (function(superClass) {
      extend(Live, superClass);

      function Live() {
        this.processProgramsResponse = bind(this.processProgramsResponse, this);
        this.updateProgramForStream = bind(this.updateProgramForStream, this);
        this.updatePrograms = bind(this.updatePrograms, this);
        this.timeCheck = bind(this.timeCheck, this);
        this.renderPrograms = bind(this.renderPrograms, this);
        this.renderActiveProgram = bind(this.renderActiveProgram, this);
        this.changeStream = bind(this.changeStream, this);
        return Live.__super__.constructor.apply(this, arguments);
      }

      Live.prototype.activeStream = null;

      Live.prototype.params = null;

      Live.prototype.defaultProgramLabel = "Who's On:";

      Live.prototype.wrapper = "#station-audio-wrapper";

      Live.prototype.swfPath = "/sites/all/themes/custom/kbooui/bower_components/jPlayer/dist/jplayer/jquery.jplayer.swf";

      Live.prototype.updateInterval = 1;

      Live.prototype.streams = {
        one: {
          route: "http://live.kboo.fm:8000/high",
          title: "KBOO",
          nodeTitle: "stream 1",
          programLabel: "",
          programDefault: "",
          program: null,
          time: null,
          $el: null
        }
      };

      Live.prototype.$active = null;

      Live.prototype.$player = null;

      Live.prototype.$programInfo = null;

      Live.prototype.init = function() {
        var $wrapper, container, minute;
        Live.__super__.init.call(this);
        minute = 60000;
        this.updateInterval *= minute;
        $wrapper = $(this.wrapper);
        this.$player = $wrapper.find(".jp-jplayer");
        container = $wrapper.find(".jp-audio").attr("id");
        this.$programInfo = $(".program-info");
        this.$player.jPlayer({
          cssSelectorAncestor: "#" + container,
          swfPath: this.swfPath,
          preload: "none",
          wmode: "window"
        });
        C4.Utilities.Timer.delay(this.updatePrograms, 1000, "audio_player_init_update");
        C4.Utilities.Timer.repeat(this.timeCheck, this.updateInterval, "audio_player_repeat_update");
        this.changeStream("one");
        return true;
      };

      Live.prototype.changeStream = function(requestedStream) {
        this.active = requestedStream;
        this.play(this.streams[requestedStream].route);
        this.renderActiveProgram();
        return true;
      };

      Live.prototype.renderActiveProgram = function() {
        var template_data;
        if (this.active == null) {
          return;
        }
        template_data = {
          label: this.streams[this.active].programLabel,
          title: this.streams[this.active].program,
          time: this.streams[this.active].time
        };
        this.$programInfo.render(template_data);
        return true;
      };

      Live.prototype.renderPrograms = function() {
        this.renderActiveProgram();
        return true;
      };

      Live.prototype.timeCheck = function() {
        var d, five, minutes, zero;
        d = new Date();
        minutes = d.getMinutes();
        zero = minutes === 0;
        five = (modulo(minutes, 5)) === 0;
        if (zero || five) {
          this.updatePrograms();
        }
        return true;
      };

      Live.prototype.updatePrograms = function() {
        var timestamp;
        timestamp = Math.floor(Date.now() / 1000);
        this.updateProgramForStream("one", timestamp);
        return true;
      };

      Live.prototype.updateProgramForStream = function(key, timestamp) {
        var nodeTitle, params, route;
        nodeTitle = this.streams[key].nodeTitle;
        route = "/api/schedule/episode/" + nodeTitle + "/at/" + timestamp;
        params = {
          type: "GET",
          url: route,
          datatype: "json",
          success: (function(_this) {
            return function(response) {
              return _this.processProgramsResponse(response, key);
            };
          })(this)
        };
        jQuery.ajax(params);
        return true;
      };

      Live.prototype.processProgramsResponse = function(response, key) {
        this.streams[key].programLabel = this.defaultProgramLabel;
        this.streams[key].program = this.streams[key].programDefault;
        this.streams[key].time = "";
        if (response.length !== 0) {
          this.streams[key].program = response[0].title;
          this.streams[key].time = response[0].start.formatted_time;
        }
        this.renderPrograms();
        return true;
      };

      Live.prototype.play = function(endpoint) {
        this.$player.jPlayer("setMedia", {
          mp3: endpoint
        });
        this.$player.jPlayer("play");
        return true;
      };

      return Live;

    })(C4.Components.Base);
    return $(function() {
      new App.Player.Live();
      return true;
    });
  })(jQuery);

}).call(this);

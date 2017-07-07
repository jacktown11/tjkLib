
function EventTargetTJK(){
	this.handlers = {};
}
EventTargetTJK.prototype = {
	constructor: EventTarget,
	addHandler: function(type,handler){
		if(typeof this.handlers[type] === "undefined"){
			this.handlers[type] = [];
		}
		this.handlers[type].push(handler);
	},
	fire: function(event){
		if(!event.target){
			event.target = this;
		}
		if(this.handlers[event.type] instanceof Array){
			var handlers = this.handlers[event.type];
			for(var i = 0; i < handlers.length; i++){
				handlers[i](event);
			}
		}
	},
	removeHandler: function(type,handler){
		if(this.handlers[type] instanceof Array){
			var handlers = this.handlers[type];
			for(var i = 0; i < handlers.length; i++){
				if(handlers[i] === handler){
					break;
				}
			}

			handlers.splice(i,1);
		}
	}
};

var EventUtilTJK = {
		addHandler: function(element,type,handler){
			if(element.addEventListener){
				element.addEventListener(type,handler,false);
			}else if(element.attachEvent){
				element.attachEvent("on" + type, handler);
			}else{
				element["on" + type] = handler;
			}
		},
		removeHandler: function(){
			if(element.addEventListener){
				element.removeEventListener(type, handler, false);
			}else if(element.detachEvent){
				element.detachEvent("on" + type, handler);
			}else{
				element["on" + type] = null;
			}
		},
		getEvent: function(event){
			return event ? event : window.event;
		},
		getTarget: function(event){
			return event.target || event.srcElement;
		},
		preventDefault: function(event){
			if(event.preventDefault){
				event.preventDefault();
			}else{
				event.returnValue = false;
			}
		},
		stopPropagation: function(event){
			if(event.stopPropagation){
				event.stopPropagation();
			}else{
				event.cancelBubble = true;
			}
		}
	},
	DragDropTJK = function(){
		var dragdrop = new EventTarget(),
			dragging = null,
			diffX = 0,
			diffY = 0;
		function handleEvent(event){
			event = EventUtilTJK.getEvent(event);
			var target = EventUtilTJK.getTarget(event);

			switch(event.type){
				case "mousedown":
					if(target.className.indexOf("draggable") > -1){
						dragging = target;
						diffX = event.clientX - target.offsetLeft;
						diffY = event.clientY - target.offsetHeight;
						dragdrop.fire({
							type: "dragstart",
							target: dragging,
							X: event.clientX,
							Y: event.clientY
						});
					}
					break;
				case "mousemove":
					if(dragging !== null){
						target.offsetLeft = event.clientX - diffX;
						target.offsetTop = event.clientY -diffY;
						dragdrop.fire({
								type: "drag",
								target: dragging,
								X: event.clientX,
								Y: event.clientY
							});						
					}
					break;
				case "mouseup":
					if(dragging !== null){
						dragdrop.fire({
								type: "dragend",
								target: dragging,
								X: event.clientX,
								Y: event.clientY
							});
						dragging = null;					
					}
					break;
			}
		}();

		dragdrop.enable = function(){
			EventUtilTJK.addHandler(document,"mousedown",handleEvent);
			EventUtilTJK.addHandler(document,"mousemove",handleEvent);
			EventUtilTJK.addHandler(document,"mouseup",handleEvent);
		};
		dragdrop.disable = function(){
			EventUtilTJK.removeHandler(document,"mousedown",handleEvent);
			EventUtilTJK.removeHandler(document,"mousemove",handleEvent);
			EventUtilTJK.removeHandler(document,"mouseup",handleEvent);
		};

		return dragdrop;
	};


function getRandomIntTJK(minNum,maxNum){
	if(typeof minNum === "number" && typeof maxNum === "number"){
		var min = parseInt(minNum),
			max = parseInt(maxNum);
		return Math.floor(Math.random()*(max-min+1)) + min;
	}
}
function getRandomColorStrTJK(){
	var str = "000000"+getRandomInt(0,0xffffff).toString(16);
	return "#" + str.slice(str.length-6);
}
function htmlEscapeTJK(str){
	if(typeof str === "string"){
		return str
            .replace(/&/g, "&amp;")
            .replace(/"/g, "&quot;")
            .replace(/'/g, "&#39;")
            .replace(/</g, "&lt;")
            .replace(/>/g, "&gt;");
	}
}

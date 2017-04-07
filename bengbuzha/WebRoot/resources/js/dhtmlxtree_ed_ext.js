
/*
===================================================================
Copyright DHTMLX LTD. http://www.dhtmlx.com
This code is obfuscated and not allowed for any purposes except 
using on sites which belongs to DHTMLX LTD.

Please contact sales@dhtmlx.com to obtain necessary 
license for usage of dhtmlx components.
===================================================================
*/
C.prototype.enableItemEditor = function (mode) {
	this.ale = K(mode);
	if (!this.ZP) {
		this.Ia = true;
		this.HY = true;
		this.aos = this.asf;
		this.XG = this.aco;
		this.mY(function (a, b) {
			if (this.HY) {
				this.KB(a, b);
			}
			return true;
		});
		this.ck(function (a, b) {
			this.TT(a, b);
			if ((this.Uh == a) && (this.Ia)) {
				this.KB(a, b);
			}
			this.Uh = a;
			return true;
		});
		this.ZP = true;
	}
};
C.prototype.Nh = function (aQ) {
	this.attachEvent("onEdit", aQ);
};
C.prototype.JM = function (afV, dblclick) {
	this.Ia = K(afV);
	this.HY = K(dblclick);
};
C.prototype.zo = function (a) {
	if (this.gp) {
		this.ko = this.Wo;
		if (this.gp.id != a) {
			var mu = true;
			mu = this.callEvent("onEdit", [2, this.gp.id, this, this.gp.span.childNodes[0].value]);
			if (mu === true) {
				mu = this.gp.span.childNodes[0].value;
			} else {
				if (mu === false) {
					mu = this.gp.Tp;
				}
			}
			var changed = (mu != this.gp.Tp);
			this.gp.span.innerHTML = mu;
			this.gp.label = this.gp.span.innerHTML;
			var arA = this.gp.tA ? "selectedTreeRow" : "standartTreeRow";
			this.gp.span.className = arA;
			this.gp.span.parentNode.className = "standartTreeRow";
			this.gp.span.style.paddingRight = this.gp.span.style.paddingLeft = "5px";
			this.gp.span.onclick = function () {
			};
			var id = this.gp.id;
			if (this.fo) {
				this.fH(this.gp);
			}
			this.gp = null;
			this.callEvent("onEdit", [3, id, this, changed]);
			if (this.Tf) {
				this.parentObject.lastChild.focus();
				this.parentObject.lastChild.focus();
			}
		}
	}
};
C.prototype.TT = function (id, tree) {
	this.zo(id);
};
C.prototype.xS = function () {
	if (this.gp) {
		this.zo(this.gp.id + "_non");
	}
};
C.prototype.WH = function (id) {
	this.KB(id, this);
};
C.prototype.KB = function (id, tree) {
	if (this.ale) {
		this.zo();
		var AT = this.ak(id);
		if (!AT) {
			return;
		}
		mu = this.callEvent("onEdit", [0, id, this, AT.span.innerHTML]);
		if (mu === true) {
			mu = AT.label;
		} else {
			if (mu === false) {
				return;
			}
		}
		this.Wo = this.ko;
		this.ko = false;
		this.gp = AT;
		AT.Tp = mu;
		AT.span.innerHTML = "<input type='text' class='intreeeditRow' />";
		AT.span.style.paddingRight = AT.span.style.paddingLeft = "0px";
		AT.span.childNodes[0].value = mu;
		AT.span.childNodes[0].onselectstart = function (e) {
			(e || event).cancelBubble = true;
			return true;
		};
		AT.span.childNodes[0].onmousedown = function (e) {
			(e || event).cancelBubble = true;
			return true;
		};
		AT.span.childNodes[0].focus();
		AT.span.childNodes[0].focus();
		AT.span.onclick = function (e) {
			(e || event).cancelBubble = true;
			return false;
		};
		AT.span.className = "";
		AT.span.parentNode.className = "";
		var self = this;
		AT.span.childNodes[0].onkeydown = function (e) {
			if (!e) {
				e = window.event;
			}
			if (e.keyCode == 13) {
				e.cancelBubble = true;
				self.zo(-1);
			} else {
				if (e.keyCode == 27) {
					self.gp.span.childNodes[0].value = self.gp.Tp;
					self.zo(-1);
				}
			}
			(e || event).cancelBubble = true;
		};
		this.callEvent("onEdit", [1, id, this]);
	}
};


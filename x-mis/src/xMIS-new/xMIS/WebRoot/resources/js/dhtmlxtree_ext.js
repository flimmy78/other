
/*
===================================================================
Copyright DHTMLX LTD. http://www.dhtmlx.com
This code is obfuscated and not allowed for any purposes except 
using on sites which belongs to DHTMLX LTD.

Please contact sales@dhtmlx.com to obtain necessary 
license for usage of dhtmlx components.
===================================================================
*/
function qJ(data) {
	this.d = data;
}
qJ.prototype = {text:function () {
	if (!aq) {
		return this.d.xml;
	}
	var x = new XMLSerializer();
	return x.serializeToString(this.d);
}, get:function (name) {
	return this.d.getAttribute(name);
}, exists:function () {
	return !!this.d;
}, content:function () {
	return this.d.firstChild ? this.d.firstChild.data : "";
}, Kw:function (name, f, t, i) {
	var a = this.d.childNodes;
	var c = new qJ();
	if (a.length) {
		for (i = i || 0; i < a.length; i++) {
			if (a[i].tagName == name) {
				c.d = a[i];
				if (f.apply(t, [c, i]) == -1) {
					return;
				}
			}
		}
	}
}, Zn:function () {
	var a = {};
	var b = this.d.attributes;
	for (var i = 0; i < b.length; i++) {
		a[b[i].name] = b[i].value;
	}
	return a;
}, sub:function (name) {
	var a = this.d.childNodes;
	var c = new qJ();
	if (a.length) {
		for (var i = 0; i < a.length; i++) {
			if (a[i].tagName == name) {
				c.d = a[i];
				return c;
			}
		}
	}
}, up:function (name) {
	return new qJ(this.d.parentNode);
}, set:function (name, val) {
	this.d.setAttribute(name, val);
}, QF:function (name) {
	return new qJ(this.d);
}, tX:function (name) {
	var a = this.d.childNodes;
	if (a.length) {
		for (var i = 0; i < a.length; i++) {
			if (a[i].tagName == name) {
				return true;
			}
		}
	}
	return false;
}, through:function (name, rule, v, f, t) {
	var a = this.d.childNodes;
	if (a.length) {
		for (var i = 0; i < a.length; i++) {
			if (a[i].tagName == name && a[i].getAttribute(rule) != null && a[i].getAttribute(rule) != "" && (!v || a[i].getAttribute(rule) == v)) {
				var c = new qJ(a[i]);
				f.apply(t, [c, i]);
			}
			var w = this.d;
			this.d = a[i];
			this.through(name, rule, v, f, t);
			this.d = w;
		}
	}
}};
function C(aI, width, height, fO) {
	if (_isIE) {
		try {
			document.execCommand("BackgroundImageCache", false, true);
		}
		catch (e) {
		}
	}
	if (typeof (aI) != "object") {
		this.parentObject = document.getElementById(aI);
	} else {
		this.parentObject = aI;
	}
	this.parentObject.style.overflow = "hidden";
	this.Xy = true;
	this.jB = ",";
	this.aep = false;
	this.enableIEImageFix();
	this.ku = 0;
	this.acE = "tree";
	this.xL = true;
	this.width = width;
	this.height = height;
	this.fO = fO;
	this.fo = null;
	this.ST = "18px";
	this.SR = "18px";
	this.Rr = "18px";
	this.QQ = "18px";
	this.jG = new Array();
	this._selected = new Array();
	this.Id = "pointer";
	if (_isIE) {
		this.Id = "hand";
	}
	this.Jm = true;
	this.sP = " [";
	this.htmlcB = "]";
	this.Rs = window;
	this.Hb = 0;
	this.Li = 0;
	this.iconURL = "";
	this.mj = 0;
	this.Es = false;
	this.PZ = true;
	this.acX = 0;
	this.rN = new Array();
	this.fs = 0;
	this.ek = 0;
	this.gQ = {};
	this.SV = 0;
	this.Fc = true;
	this.tO = false;
	this.We = true;
	this.BM = false;
	this.xA = null;
	this.HM = [];
	this.mF = window.fe || "";
	this.Bq = new Array("iconUncheckAll.gif", "iconCheckAll.gif", "iconCheckGray.gif", "iconUncheckDis.gif", "iconCheckDis.gif", "iconCheckDis.gif");
	this.GR = new Array("radio_off.gif", "radio_on.gif", "radio_on.gif", "radio_off.gif", "radio_on.gif", "radio_on.gif");
	this.wf = new Array("line2.gif", "line3.gif", "line4.gif", "blank.gif", "blank.gif", "line1.gif");
	this.mQ = new Array("minus2.gif", "minus3.gif", "minus4.gif", "minus.gif", "minus5.gif");
	this.nj = new Array("plus2.gif", "plus3.gif", "plus4.gif", "plus.gif", "plus5.gif");
	this.gZ = new Array("leaf.gif", "folderOpen.gif", "folderClosed.gif");
	this.ary = new Array(0, 0, 0);
	this.agE = "but_cut.gif";
	dhtmlxEventable(this);
	this.M = new J();
	
	this.ao = new mU(this.fO, "", 0, this);
	this.ao.ao.childNodes[0].childNodes[0].style.display = "none";
	this.ao.ao.childNodes[0].childNodes[0].childNodes[0].className = "hiddenRow";
	this.cB = this.na();
	this.cB.appendChild(this.ao.ao);
	if (aq) {
		this.cB.childNodes[0].width = "100%";
		this.cB.childNodes[0].style.overflow = "hidden";
	}

	var self = this;
	this.cB.onselectstart = new Function("return false;");
	if (gP) {
		this.cB.oncontextmenu = function (e) {
			return self._doContClick(e || window.event);
		};
	}
	
	this.cB.onmousedown = function (e) {
		return self._doContClick(e || window.event);
	};
	this.dF = new ag(this.hf, this, true, this.ir);
	if (_isIE) {
		this.jJ(true);
	}
	this.selectionBar = document.createElement("DIV");
	this.selectionBar.className = "selectionBar";
	this.selectionBar.innerHTML = "&nbsp;";
	this.selectionBar.style.display = "none";
	this.cB.appendChild(this.selectionBar);
	if (window.addEventListener) {
		window.addEventListener("unload", function () {
			try {
				self.fA();
			}
			catch (e) {
			}
		}, false);
	}
	if (window.attachEvent) {
		window.attachEvent("onunload", function () {
			try {
				self.fA();
			}
			catch (e) {
			}
		});
	}
	
	this.setImagesPath = this.setImagePath;
	this.setIconsPath = this.setIconPath;
	if (dhtmlx.image_path) {
		this.setImagePath(dhtmlx.image_path);
	}
	if (dhtmlx.skin) {
		this.setSkin(dhtmlx.skin);
	}
	return this;
}
C.prototype.amB = function (mode) {
	this.Kl = mode;
};
C.prototype._doContClick = function (ev) {
	if (ev.button != 2) {
		if (this.Lt) {
			if (this.Lt.hideContextMenu) {
				this.Lt.hideContextMenu();
			} else {
				this.Hb.ES();
			}
		}
		return true;
	}
	var el = (_isIE ? ev.srcElement : ev.target);
	while ((el) && (el.tagName != "BODY")) {
		if (el.parentObject) {
			break;
		}
		el = el.parentNode;
	}
	if ((!el) || (!el.parentObject)) {
		return true;
	}
	var obj = el.parentObject;
	if (!this.callEvent("onRightClick", [obj.id, ev])) {
		(ev.srcElement || ev.target).oncontextmenu = function (e) {
			(e || event).cancelBubble = true;
			return false;
		};
	}
	this.Lt = (obj.Hb || this.Hb);
	if (this.Lt) {
		if (!(this.callEvent("onBeforeContextMenu", [obj.id]))) {
			return true;
		}
		(ev.srcElement || ev.target).oncontextmenu = function (e) {
			(e || event).cancelBubble = true;
			return false;
		};
		if (this.Lt.showContextMenu) {
			this.Lt.showContextMenu(ev.clientX - 1, ev.clientY - 1);
			this.contextID = obj.id;
			ev.cancelBubble = true;
			this.Lt._skip_hide = true;
		} else {
			el.contextMenuId = obj.id;
			el.contextMenu = this.Lt;
			el.a = this.Lt.vm;
			el.a(el, ev);
			el.a = null;
		}
		return false;
	}
	return true;
};
C.prototype.enableIEImageFix = function (mode) {
	if (!mode) {
		this.Lg = function (id) {
			return document.createElement((id == this.fO) ? "div" : "img");
		};
		this.Rx = function (a, b) {
			a.src = b;
		};
		this.YW = function (a) {
			return a.src;
		};
	} else {
		this.Lg = function () {
			var z = document.createElement("DIV");
			z.innerHTML = "&nbsp;";
			z.className = "dhx_bg_img_fix";
			return z;
		};
		this.Rx = function (a, b) {
			a.style.backgroundImage = "url(" + b + ")";
		};
		this.YW = function (a) {
			var z = a.style.backgroundImage;
			return z.substr(4, z.length - 5);
		};
	}
};
C.prototype.fA = function () {
	for (var a in this.gQ) {
		var z = this.gQ[a];
		if (!z) {
			continue;
		}
		z.parentObject = null;
		z.treeNod = null;
		z.childNodes = null;
		z.span = null;
		z.tr.mX = null;
		z.tr = null;
		z.ao.Jh = null;
		z.ao = null;
		this.gQ[a] = null;
	}
	this.parentObject.innerHTML = "";
	if (this.dF) {
		this.dF.fA();
	}
	this.cB.onselectstart = null;
	this.cB.oncontextmenu = null;
	this.cB.onmousedown = null;
	for (var a in this) {
		this[a] = null;
	}
};
function Fn() {
	return this;
}
Fn.prototype = new Object;
Fn.prototype.QF = function () {
	function adK() {
	}
	adK.prototype = this;
	return new adK();
};
function mU(itemId, itemText, parentObject, bG, eP, mode) {
	this.ao = "";
	this.kP = "";
	this.mB = "";
	this.tr = 0;
	this.aE = 0;
	this.dH = 0;
	this.dG = 0;
	this.fj = 0;
	this.MP = 0;
	this.span = 0;
	this.ro = 1;
	this.childNodes = new Array();
	this.userData = new Fn();
	this.cY = 0;
	this.treeNod = bG;
	this.label = itemText;
	this.parentObject = parentObject;
	this.eP = eP;
	
	this.images = new Array(bG.gZ[0], bG.gZ[1], bG.gZ[2]);
	this.id = bG.oh(itemId, this);
	if (this.treeNod.ps) {
		this.ao = this.treeNod.ux(1, this, mode);
	} else {
		this.ao = this.treeNod.ux(0, this, mode);
	}
	this.ao.Jh = this;
	return this;
}
C.prototype.oh = function (itemId, aa) {
	if (this.ak(itemId, 1, 1)) {
		itemId = itemId + "_" + (new Date()).valueOf();
		return this.oh(itemId, aa);
	}
	this.gQ[itemId] = aa;
	this.SV++;
	return itemId;
};
C.prototype.rW = function (itemId) {
	if (this.gQ[itemId]) {
		this.rH(this.gQ[itemId]);
		this.gQ[itemId] = null;
		this.SV--;
	}
	if ((this.nG) && (this.nG[itemId])) {
		this.nG[itemId] = false;
	}
};
C.prototype.ak = function (itemId, AE, pd, acV) {
	var z = this.gQ[itemId];
	if (z) {
		if ((z.bZ) && (!pd)) {
			this.tK(z, 0);
		}
		if (this.ahK && !z.ao) {
			this.aaQ(z, pd);
		}
		if ((acV) && (this.hv)) {
			for (var j = 0; j < this.hv.length; j++) {
				if (this.hv[j][2] == itemId) {
					ey.gn("getItem", "Requested item still in parsing process.", itemId);
					return null;
				}
			}
		}
		return z;
	}
	if ((this.Es) && (itemId != 0) && (!AE)) {
		return this.afN(itemId);
	} else {
		return null;
	}
};
C.prototype.Qo = function (p) {
	var z = [];
	p.Kw("item", function (c) {
		z.push(c.get("id"));
	}, this);
	return z.join(",");
};
C.prototype.enableSmartXMLParsing = function (mode) {
	this.Es = K(mode);
};
C.prototype.aqs = function (node, asv, val) {
};
C.prototype.LU = function (p, list, mode) {
	var z = [];
	if (mode == 2) {
		p.through("item", "checked", mode, function (c) {
			z.push(c.get("id"));
		}, this);
	}
	if (mode == 1) {
		p.through("item", "id", null, function (c) {
			if (c.get("checked") && (c.get("checked") != -1)) {
				z.push(c.get("id"));
			}
		}, this);
	}
	if (mode == 0) {
		p.through("item", "id", null, function (c) {
			if (!c.get("checked") || c.get("checked") == 0) {
				z.push(c.get("id"));
			}
		}, this);
	}
	return list + (list ? "," : "") + z.join(",");
	if (list) {
		return list;
	} else {
		return "";
	}
};
C.prototype.LT = function (state, p) {
	var val = state ? "1" : "";
	p.through("item", "id", null, function (c) {
		c.set("checked", val);
	}, this);
};
C.prototype.uD = function (p, x) {
	var z = [];
	var aeB = function (c) {
		if (!c.tX("item")) {
			z.push(c.get("id"));
		} else {
			c.Kw("item", aeB, this);
		}
	};
	aeB(p);
	return z.join(",");
};
C.prototype.zW = function (p, x) {
	var z = [];
	var aeB = function (c) {
		if (!c.tX("item")) {
			return;
		}
		z.push(c.get("id"));
		c.Kw("item", aeB, this);
	};
	aeB(p);
	return z.join(",");
};
C.prototype.Ku = function (itemId, z, p) {
	var z = [];
	p.through("item", "id", null, function (c) {
		z.push(c.get("id"));
	}, this);
	return z.join(",");
};
C.prototype.tK = function (node) {
	var that = this;
	if (!this.lQ) {
		that.callEvent("onXLS", [that, node.id]);
	}
	this.ku = 1;
	var YV = node.bZ;
	node.bZ = 0;
	this.ek = 1;
	var ame = this.tw;
	var anH = this.hL;
	var anM = this.jy;
	this.jy = new Array();
	this.hL = false;
	this.tw = node.id;
	this.jy = new Array();
	this.sK = "";
	this.Aq(YV, node.id, 2);
	var wG = this.sK.split(this.jB);
	for (var i = 0; i < this.jy.length; i++) {
		node.ao.childNodes[0].appendChild(this.jy[i]);
	}
	if (YV.get("order") && YV.get("order") != "none") {
		this.tM(node, YV.get("order"), true);
	}
	this.abn = this.xL;
	this.xL = false;
	for (var n = 0; n < wG.length; n++) {
		if (wG[n]) {
			this.mA(wG[n], 1);
		}
	}
	this.xL = this.abn;
	this.tw = ame;
	this.hL = anH;
	this.jy = anM;
	this.ek = 0;
	this.jm(this, node);
	if (this.ahK && !node.Rb) {
		this.zz(node.id);
	}
	this.ku = 0;
	return true;
};
C.prototype.afN = function (itemId) {
	if (!itemId || !this.Pv) {
		return null;
	}
	var result = false;
	this.Pv.QF().through("item", "id", itemId, function (c) {
		this.ak(c.up().get("id"));
		return result = true;
	}, this);
	if (result) {
		var n = this.ak(itemId, true, false);
		if (!n) {
			ey.gn("getItem", "The item " + itemId + " not operable. Seems you have non-unique|incorrect IDs in tree's XML.", itemId);
		}
	}
	return n;
};
C.prototype.xZ = function (str) {
	switch (this.aeh) {
	  case "none":
		return str;
		break;
	  case "utf8":
		return encodeURIComponent(str);
		break;
	  default:
		return escape(str);
		break;
	}
};
C.prototype.YT = function (aI, node) {
	var tr = document.createElement("tr");
	var xp = document.createElement("td");
	var Bb = document.createElement("td");
	xp.appendChild(document.createTextNode(" "));
	Bb.colSpan = 3;
	Bb.appendChild(aI);
	tr.appendChild(xp);
	tr.appendChild(Bb);
	return tr;
};
C.prototype.loadXMLString = function (RA, bo) {
	var that = this;
	if (!this.lQ) {
		this.callEvent("onXLS", [that, null]);
	}
	this.ku = 1;
	if (bo) {
		this.dF.bs = bo;
	}
	this.dF.loadXMLString(RA);
};
C.prototype.loadXML = function (file, bo) {
	if (this.Kl && this.Kl != "xml") {
		return this["load" + this.Kl.toUpperCase()](file, bo);
	}
	var that = this;
	if (!this.lQ) {
		this.callEvent("onXLS", [that, this.xA]);
	}
	this.xA = null;
	this.ku = 1;
	this.dF = new ag(this.hf, this, true, this.ir);
	if (bo) {
		this.dF.bs = bo;
	}
	this.dF.loadXML(file);
};
C.prototype.kV = function (parentObject, itemId, itemText, kA, kQ, kS, nI, kC, bu, bT, JU) {
	if (bT && bT.parentObject) {
		parentObject = bT.parentObject;
	}
	if (((parentObject.fS == 0) && (this.fs)) && (!this.ek)) {
		parentObject.fS = 1;
		this.pA(parentObject.id);
	}
	var Count = parentObject.aE;
	var dN = parentObject.childNodes;
	if (JU) {
		if (JU.tr.previousSibling.previousSibling) {
			bT = JU.tr.previousSibling.mX;
		} else {
			kC = kC.replace("TOP", "") + ",TOP";
		}
	}
	if (bT) {
		var ik, jk;
		for (ik = 0; ik < Count; ik++) {
			if (dN[ik] == bT) {
				for (jk = Count; jk != ik; jk--) {
					dN[1 + jk] = dN[jk];
				}
				break;
			}
		}
		ik++;
		Count = ik;
	}
	if (kC) {
		var FZ = kC.split(",");
		for (var i = 0; i < FZ.length; i++) {
			switch (FZ[i]) {
			  case "TOP":
				if (parentObject.aE > 0) {
					bT = new Object;
					bT.tr = parentObject.childNodes[0].tr.previousSibling;
				}
				parentObject.agc = true;
				for (ik = Count; ik > 0; ik--) {
					dN[ik] = dN[ik - 1];
				}
				Count = 0;
				break;
			}
		}
	}
	var n;
	if (!(n = this.gQ[itemId]) || n.span != -1) {
		n = dN[Count] = new mU(itemId, itemText, parentObject, this, kA, 1);
		itemId = dN[Count].id;
		parentObject.aE++;
	}
	if (!n.ao) {
		n.label = itemText;
		n.ao = this.ux((this.ps ? 1 : 0), n);
		n.ao.Jh = n;
	}
	if (kQ) {
		n.images[0] = kQ;
	}
	if (kS) {
		n.images[1] = kS;
	}
	if (nI) {
		n.images[2] = nI;
	}
	var tr = this.YT(n.ao);
	if ((this.ek) || (this.agX)) {
		n.ao.parentNode.parentNode.style.display = "none";
	}
	if ((bT) && (bT.tr.nextSibling)) {
		parentObject.ao.childNodes[0].insertBefore(tr, bT.tr.nextSibling);
	} else {
		if (this.tw == parentObject.id) {
			this.jy[this.jy.length] = tr;
		} else {
			parentObject.ao.childNodes[0].appendChild(tr);
		}
	}
	if ((bT) && (!bT.span)) {
		bT = null;
	}
	if (this.fs) {
		if ((bu) && (bu != 0)) {
			n.fS = 0;
		} else {
			n.fS = 1;
		}
	}
	n.tr = tr;
	tr.mX = n;
	if (parentObject.itemId == 0) {
		tr.childNodes[0].className = "hiddenRow";
	}
	if ((parentObject.nN) || (this.Co)) {
		this.Rx(n.ao.childNodes[0].childNodes[0].childNodes[1].childNodes[0], this.mF + this.GR[0]);
	}
	if (kC) {
		var FZ = kC.split(",");
		for (var i = 0; i < FZ.length; i++) {
			switch (FZ[i]) {
			  case "SELECT":
				this.hE(itemId, false);
				break;
			  case "CALL":
				this.hE(itemId, true);
				break;
			  case "CHILD":
				n.fS = 0;
				break;
			  case "CHECKED":
				if (this.ek) {
					this.sK += this.jB + itemId;
				} else {
					this.mA(itemId, 1);
				}
				break;
			  case "HCHECKED":
				this.bL(n, "unsure");
				break;
			  case "OPEN":
				n.Xm = 1;
				break;
			}
		}
	}
	if (!this.ek) {
		if ((this.dD(parentObject) < 0) && (!this.agX)) {
			this.hx(parentObject.id);
		}
		if (bT) {
			this.cE(bT);
			this.gK(bT);
		}
		this.cE(parentObject);
		this.gK(parentObject);
		this.cE(n);
		if (parentObject.aE >= 2) {
			this.cE(dN[parentObject.aE - 2]);
			this.gK(dN[parentObject.aE - 2]);
		}
		if (parentObject.aE != 2) {
			this.cE(dN[0]);
		}
		if (this.tO) {
			this.gU(parentObject);
		}
		if (this.BX) {
			if (this.ku == 1) {
				var old = this.onXLE;
				this.onXLE = function (id) {
					this.BX(itemId);
					if (old) {
						old(id);
					}
				};
			} else {
				this.BX(itemId);
			}
		}
	}
	return n;
};
C.prototype.enableContextMenu = function (menu) {
	if (menu) {
		this.Hb = menu;
	}
};
C.prototype.adc = function (itemId, Hb) {
	var l = itemId.toString().split(this.jB);
	for (var i = 0; i < l.length; i++) {
		var AT = this.ak(l[i]);
		if (!AT) {
			continue;
		}
		AT.Hb = Hb;
	}
};
C.prototype.insertNewItem = function (parentId, itemId, itemText, kA, kQ, kS, nI, kC, children) {
	var parentObject = this.ak(parentId);
	if (!parentObject) {
		return (-1);
	}
	var aaN = this.kV(parentObject, itemId, itemText, kA, kQ, kS, nI, kC, children);
	if ((!this.ek) && (this.fo)) {
		this.fH(parentObject);
	}
	return aaN;
};
C.prototype.cH = function (parentId, itemId, itemText, kA, kQ, kS, nI, kC, children) {
	return this.insertNewItem(parentId, itemId, itemText, kA, kQ, kS, nI, kC, children);
};
C.prototype.hf = function (a, b, c, d, xml) {
	var p = new qJ(xml.cR("tree"));
	a.Aq(p);
	a.Pv = p;
};
C.prototype.OU = function (c, AT, yc, ajw) {
	var id;
	if (this.ahK && (!this.gQ[id = c.get("id")] || !this.gQ[id].span)) {
		this.WE(AT.id, id, c);
		return;
	}
	var a = c.Zn();
	if ((typeof (this.hL) == "object") && (!this.hL[a.id])) {
		this.Aq(c, a.id, 1);
		return;
	}
	if ((a.text === null) || (typeof (a.text) == "undefined")) {
		a.text = c.sub("itemtext");
		if (a.text) {
			a.text = a.text.content();
		}
	}
	var Tj = [];
	if (a.select) {
		Tj.push("SELECT");
	}
	if (a.top) {
		Tj.push("TOP");
	}
	if (a.call) {
		this.qf = a.id;
	}
	if (a.checked == -1) {
		Tj.push("HCHECKED");
	} else {
		if (a.checked) {
			Tj.push("CHECKED");
		}
	}
	if (a.open) {
		Tj.push("OPEN");
	}
	if (this.hL) {
		if (this.ak(a.id)) {
			var fi = this.aak(a.id, a.text, a.im0, a.im1, a.im2, a.checked);
		} else {
			if (this.Za == 0) {
				Tj.push("TOP");
			} else {
				yc = AT.childNodes[this.Za];
			}
			var fi = this.kV(AT, a.id, a.text, 0, a.im0, a.im1, a.im2, Tj.join(","), a.child, 0, yc);
			yc = null;
		}
	} else {
		var fi = this.kV(AT, a.id, a.text, 0, a.im0, a.im1, a.im2, Tj.join(","), a.child, (ajw || 0), yc);
	}
	if (a.tooltip) {
		fi.span.parentNode.parentNode.title = a.tooltip;
	}
	if (a.style) {
		if (fi.span.style.cssText) {
			fi.span.style.cssText += (";" + a.style);
		} else {
			fi.span.setAttribute("style", fi.span.getAttribute("style") + ";" + a.style);
		}
	}
	if (a.radio) {
		fi.nN = true;
	}
	if (a.BC) {
		var check_node = fi.span.parentNode.previousSibling.previousSibling;
		check_node.childNodes[0].style.display = "none";
		if (window._KHTMLrv) {
			check_node.style.display = "none";
		}
		fi.BC = true;
	}
	if (a.disabled) {
		if (a.checked != null) {
			this.bL(fi, a.checked);
		}
		this.ox(fi, 1);
	}
	fi.ph = a.child || 0;
	if (this.DW) {
		this.DW.ahh.call(this, c, a, (AT ? AT.id : 0));
	}
	this.lF(fi, a.aCol, a.sCol);
	if (a.locked == "1") {
		this.GY(fi.id, true, true);
	}
	if ((a.ajJ) || (a.afH)) {
		this.yZ(a.ajJ, a.afH, fi);
	}
	if ((a.closeable == "0") || (a.closeable == "1")) {
		this.Cq(fi, a.closeable);
	}
	var acb = "";
	if (a.aez) {
		this.Cx(fi, a.aez);
	}
	if ((!this.Es) || (typeof (this.hL) == "object")) {
		if (c.tX("item")) {
			acb = this.Aq(c, a.id, 1);
		}
	} else {
		if ((!fi.aE) && c.tX("item")) {
			fi.bZ = c.QF();
		}
		c.Kw("userdata", function (u) {
			this.setUserData(a.id, u.get("name"), u.content());
		}, this);
	}
	if (acb != "") {
		this.qf = acb;
	}
	c.Kw("userdata", function (u) {
		this.setUserData(c.get("id"), u.get("name"), u.content());
	}, this);
};
C.prototype.Aq = function (p, parentId, gR, start) {
	if (this.ahK && !this.parentObject.offsetHeight) {
		var self = this;
		return window.setTimeout(function () {
			self.Aq(p, parentId, gR, start);
		}, 100);
	}
	if (!p.exists()) {
		return;
	}
	this.Xf = true;
	if (!parentId) {
		parentId = p.get("id");
		if (p.get("radio")) {
			this.ao.nN = true;
		}
		this.tw = parentId;
		this.jy = new Array();
		this.sK = "";
		this.qf = "";
	}
	var AT = this.ak(parentId);
	if (!AT) {
		return ey.gn("DataStructure", "XML refers to not existing parent");
	}
	this.lQ = this.lQ ? (this.lQ + 1) : 1;
	this.ek = 1;
	if ((AT.aE) && (!start) && (!this.Lz) && (!AT.agc)) {
		var yc = AT.childNodes[AT.aE - 1];
	} else {
		var yc = 0;
	}
	this.Za = 0;
	p.Kw("item", function (c, i) {
		AT.fS = 1;
		if ((this.adO) && (this.Lo == this.Za)) {
			this.Od(AT, this.Za + 1 * (start || 0), gR, node);
			return -1;
		}
		this.OU(c, AT, yc);
		if ((this.Lz) && (this.Za == this.afa)) {
			this.LH(p, i + 1, parentId, gR, AT.aE);
			return -1;
		}
		this.Za++;
	}, this, start);
	if (!gR) {
		p.Kw("userdata", function (u) {
			this.setUserData(p.get("id"), u.get("name"), u.content());
		}, this);
		AT.fS = 1;
		if (this.hL) {
			this.hL = false;
			for (var i = AT.aE - 1; i >= 0; i--) {
				if (AT.childNodes[i].acD) {
					this.deleteItem(AT.childNodes[i].id);
				}
			}
		}
		var aka = this.ak(this.tw);
		for (var i = 0; i < this.jy.length; i++) {
			AT.ao.childNodes[0].appendChild(this.jy[i]);
		}
		this.wK = parentId;
		this.ek = 0;
		var wG = this.sK.split(this.jB);
		for (var n = 0; n < wG.length; n++) {
			if (wG[n]) {
				this.mA(wG[n], 1);
			}
		}
		if ((this.fs) && (this.tO) && (this.xL) && (AT.id != this.fO)) {
			if (AT.cY === 0) {
				this.iE(0, AT);
			} else {
				if (AT.cY === 1) {
					this.iE(1, AT);
				}
			}
		}
		this.jm(this, null, start);
		if (p.get("order") && p.get("order") != "none") {
			this.tM(AT, p.get("order"), true);
		}
		if (this.qf != "") {
			this.callEvent("onClick", [this.qf, this.ah()]);
		}
		if (this.ve) {
			this.Yt(p);
		}
	}
	if (this.lQ == 1) {
		this.tw = null;
		if (this.ahK && AT.id != this.fO) {
			this.zz(AT.id);
			if (this.fs) {
				this.hx(AT.id);
			}
		}
		p.through("item", "open", null, function (c) {
			this.hx(c.get("id"));
		}, this);
		if ((!this.Lz) || (!this.hv.length)) {
			var that = this;
			window.setTimeout(function () {
				that.callEvent("onXLE", [that, parentId]);
			}, 1);
			this.ku = 0;
		}
		this.Xf = false;
	}
	this.lQ--;
	var that = this;
	if (this.Lz) {
		window.setTimeout(function () {
			that.NX(parentId);
		}, this.afv);
	}
	if ((this.adO) && (start)) {
		this.Og(AT, (start || 0), gR, node);
	}
	if (!gR && this.onXLE) {
		this.onXLE(this, parentId);
	}
	return this.qf;
};
C.prototype.Yt = function (p) {
	p.Kw("item", function (c) {
		var zX = c.get("id");
		if (this.gQ[zX] && (!this.gQ[zX].fS)) {
			return;
		}
		this.ve++;
		this.rq(c.get("id"), c);
	}, this);
	this.ve--;
};
C.prototype.akd = function (node, parentId) {
	if ((node.nodeType == 1) && (node.tagName == "userdata")) {
		var name = node.getAttribute("name");
		if ((name) && (node.childNodes[0])) {
			this.setUserData(parentId, name, node.childNodes[0].data);
		}
	}
};
C.prototype.jm = function (Ll, aa, start, aio) {
	if (!aa) {
		var fE = Ll.ak(Ll.wK);
		Ll.wK = -1;
		if (!fE) {
			return 0;
		}
	} else {
		fE = aa;
	}
	var afB = 0;
	for (var i = (start ? start - 1 : 0); i < fE.aE; i++) {
		if ((!this.ve) || (this.dD(fE) == 1)) {
			if ((!aa) || (aio == 1)) {
				fE.childNodes[i].ao.parentNode.parentNode.style.display = "";
			}
		}
		if (fE.childNodes[i].Xm == 1) {
			this.nk(fE.childNodes[i]);
			fE.childNodes[i].Xm = 0;
		}
		Ll.jm(Ll, fE.childNodes[i]);
		if (this.fo != null) {
			if ((fE.childNodes[i].bZ) || ((!fE.childNodes[i].fS) && (this.fs))) {
				if (fE.childNodes[i].ph) {
					fE.childNodes[i].span.innerHTML = fE.childNodes[i].label + this.sP + fE.childNodes[i].ph + this.htmlcB;
				} else {
					fE.childNodes[i].span.innerHTML = fE.childNodes[i].label;
				}
			}
			if ((fE.childNodes[i].childNodes.length) && (this.fo)) {
				if (this.fo == 1) {
					fE.childNodes[i].span.innerHTML = fE.childNodes[i].label + this.sP + fE.childNodes[i].aE + this.htmlcB;
				}
				if (this.fo == 2) {
					var KH = fE.childNodes[i].aE - (fE.childNodes[i].GW || 0);
					if (KH) {
						fE.childNodes[i].span.innerHTML = fE.childNodes[i].label + this.sP + KH + this.htmlcB;
					}
					if (fE.GW) {
						fE.GW++;
					} else {
						fE.GW = 1;
					}
				}
				if (this.fo == 3) {
					fE.childNodes[i].span.innerHTML = fE.childNodes[i].label + this.sP + fE.childNodes[i].ph + this.htmlcB;
				}
				if (this.fo == 4) {
					var KH = fE.childNodes[i].ph;
					if (KH) {
						fE.childNodes[i].span.innerHTML = fE.childNodes[i].label + this.sP + KH + this.htmlcB;
					}
				}
			} else {
				if (this.fo == 4) {
					afB++;
				}
			}
			afB += fE.childNodes[i].ph;
			if (this.fo == 3) {
				afB++;
			}
		}
	}
	if ((!fE.bZ) && ((fE.fS) || (!this.fs))) {
		fE.ph = afB;
	}
	Ll.gK(fE);
	Ll.cE(fE);
	if ((this.fo) && (!aa)) {
		Ll.fH(fE);
	}
};
C.prototype.na = function () {
	var div = document.createElement("div");
	div.className = "containerTableStyle";
	div.style.width = this.width;
	div.style.height = this.height;
	this.parentObject.appendChild(div);
	return div;
};
C.prototype.Ho = function (aa) {
	if (aa.bZ) {
		return;
	}
	if (this.fO != aa.id) {
		var dN = aa.ao.childNodes[0].childNodes;
		var Count = dN.length;
		for (var i = 1; i < Count; i++) {
			dN[i].style.display = "none";
		}
		this.cE(aa);
	}
	for (var i = 0; i < aa.aE; i++) {
		if (aa.childNodes[i].aE) {
			this.Ho(aa.childNodes[i]);
		}
	}
};
C.prototype.SP = function (aa) {
	this.kK(aa, 2);
	for (var i = 0; i < aa.aE; i++) {
		this.SP(aa.childNodes[i]);
	}
};
C.prototype.cE = function (aa) {
	if (!aa.ao) {
		return;
	}
	var OE = aa.ao.childNodes[0].childNodes[0].childNodes[0].lastChild;
	var OG = aa.ao.childNodes[0].childNodes[0].childNodes[2].childNodes[0];
	var Ae = this.wf;
	if ((this.fs) && (!aa.fS)) {
		var Ae = this.nj;
		this.Rx(OG, this.iconURL + aa.images[2]);
		if (this.Lu) {
			return (OE.innerHTML = "[+]");
		}
	} else {
		if ((aa.aE) || (aa.bZ)) {
			if ((aa.ao.childNodes[0].childNodes[1]) && (aa.ao.childNodes[0].childNodes[1].style.display != "none")) {
				if (!aa.abd) {
					var Ae = this.mQ;
				}
				this.Rx(OG, this.iconURL + aa.images[1]);
				if (this.Lu) {
					return (OE.innerHTML = "[-]");
				}
			} else {
				if (!aa.abd) {
					var Ae = this.nj;
				}
				this.Rx(OG, this.iconURL + aa.images[2]);
				if (this.Lu) {
					return (OE.innerHTML = "[+]");
				}
			}
		} else {
			this.Rx(OG, this.iconURL + aa.images[0]);
		}
	}
	var Zq = 2;
	if (!aa.treeNod.Fc) {
		this.Rx(OE, this.mF + Ae[3]);
	} else {
		if (aa.parentObject) {
			Zq = this.Qc(aa.id, aa.parentObject);
		}
		this.Rx(OE, this.mF + Ae[Zq]);
	}
};
C.prototype.gK = function (aa) {
	if (!aa.ao) {
		return;
	}
	var aX = aa.parentObject;
	if (aX) {
		if ((this.Sk(aa.id, aX) == 0) || (!this.Fc)) {
			for (var i = 1; i <= aa.aE; i++) {
				if (!aa.ao.childNodes[0].childNodes[i]) {
					break;
				}
				aa.ao.childNodes[0].childNodes[i].childNodes[0].style.backgroundImage = "";
				aa.ao.childNodes[0].childNodes[i].childNodes[0].style.backgroundRepeat = "";
			}
		} else {
			for (var i = 1; i <= aa.aE; i++) {
				if (!aa.ao.childNodes[0].childNodes[i]) {
					break;
				}
				aa.ao.childNodes[0].childNodes[i].childNodes[0].style.backgroundImage = "url(" + this.mF + this.wf[5] + ")";
				aa.ao.childNodes[0].childNodes[i].childNodes[0].style.backgroundRepeat = "repeat-y";
			}
		}
	}
};
C.prototype.Qc = function (itemId, aa) {
	if (aa.aE <= 1) {
		if (aa.id == this.fO) {
			return 4;
		} else {
			return 0;
		}
	}
	if (aa.childNodes[0].id == itemId) {
		if (aa.id == this.fO) {
			return 2;
		} else {
			return 1;
		}
	}
	if (aa.childNodes[aa.aE - 1].id == itemId) {
		return 0;
	}
	return 1;
};
C.prototype.Sk = function (itemId, aa) {
	if (aa.childNodes[aa.aE - 1].id == itemId) {
		return 0;
	}
	return 1;
};
C.prototype.kK = function (aa, mode) {
	if ((this.fs) && (!aa.fS)) {
		if (mode == 1) {
			return;
		}
		aa.fS = 1;
		this.pA(aa.id);
		return;
	}
	if (aa.bZ) {
		this.tK(aa);
	}
	var dN = aa.ao.childNodes[0].childNodes;
	var Count = dN.length;
	if (Count > 1) {
		if (((dN[1].style.display != "none") || (mode == 1)) && (mode != 2)) {
			this.cB.childNodes[0].border = "1";
			this.cB.childNodes[0].border = "0";
			zJ = "none";
		} else {
			zJ = "";
		}
		for (var i = 1; i < Count; i++) {
			dN[i].style.display = zJ;
		}
	}
	this.cE(aa);
};
C.prototype.dD = function (aa) {
	var z = aa.ao.childNodes[0].childNodes;
	if (z.length <= 1) {
		return 0;
	}
	if (z[1].style.display != "none") {
		return 1;
	} else {
		return -1;
	}
};
C.prototype.Mk = function () {
	var that = this.parentObject.treeNod;
	if (!that.callEvent("onDblClick", [this.parentObject.id, that])) {
		return false;
	}
	if ((this.parentObject.ro) && (this.parentObject.ro != "0")) {
		that.kK(this.parentObject);
	} else {
		that.kK(this.parentObject, 2);
	}
	if (that.mR("onOpenEnd")) {
		if (!that.ku) {
			that.callEvent("onOpenEnd", [this.parentObject.id, that.dD(this.parentObject)]);
		} else {
			that.HM.push(that.onXLE);
			that.onXLE = that.FW;
		}
	}
	return false;
};
C.prototype.PR = function () {
	var that = this.parentObject.treeNod;
	if (!that.callEvent("onOpenStart", [this.parentObject.id, that.dD(this.parentObject)])) {
		return 0;
	}
	if ((this.parentObject.ro) && (this.parentObject.ro != "0")) {
		that.kK(this.parentObject);
	} else {
		that.kK(this.parentObject, 2);
	}
	if (that.mR("onOpenEnd")) {
		if (!that.ku) {
			that.callEvent("onOpenEnd", [this.parentObject.id, that.dD(this.parentObject)]);
		} else {
			that.HM.push(that.onXLE);
			that.onXLE = that.FW;
		}
	}
};
C.prototype.FW = function (that, id, mt) {
	if (id != this.fO) {
		this.callEvent("onOpenEnd", [id, that.KL(id)]);
	}
	that.onXLE = that.HM.pop();
	if (!mt && !that.HM.length) {
		if (that.onXLE) {
			that.onXLE(that, id);
		}
	}
};
C.prototype.aiY = function (e) {
	e = e || window.event;
	var that = this.parentObject.treeNod;
	that.yM(this.parentObject, e);
};
C.prototype.ah = function () {
	var str = new Array();
	for (var i = 0; i < this._selected.length; i++) {
		str[i] = this._selected[i].id;
	}
	return (str.join(this.jB));
};
C.prototype.yM = function (node, e) {
	if (this.mR("onSelect")) {
		this.aaM = this.ah();
	}
	if ((!this.Wj) || (!e) || ((!e.ctrlKey) && (!e.metaKey) && (!e.shiftKey))) {
		this.Fo();
	}
	if ((node.tA) && (this.Wj) && (e) && (e.ctrlKey || e.metaKey)) {
		this.rH(node);
	} else {
		if ((!node.tA) && ((!this.aim) || (this._selected.length == 0) || (this._selected[0].parentObject == node.parentObject))) {
			if ((this.Wj) && (e) && (e.shiftKey) && (this._selected.length != 0) && (this._selected[this._selected.length - 1].parentObject == node.parentObject)) {
				var a = this.SA(this._selected[this._selected.length - 1]);
				var b = this.SA(node);
				if (b < a) {
					var c = a;
					a = b;
					b = c;
				}
				for (var i = a; i <= b; i++) {
					if (!node.parentObject.childNodes[i].tA) {
						this.qy(node.parentObject.childNodes[i]);
					}
				}
			} else {
				this.qy(node);
			}
		}
	}
	if (this.mR("onSelect")) {
		var z = this.ah();
		if (z != this.aaM) {
			this.callEvent("onSelect", [z]);
		}
	}
};
C.prototype.qy = function (node) {
	if (node.mB) {
		node.span.style.color = node.mB;
	}
	node.span.className = "selectedTreeRow";
	node.tA = true;
	this._selected[this._selected.length] = node;
};
C.prototype.akg = function (itemId) {
	var z = this.ak(itemId);
	if (!z) {
		return null;
	}
	return this.SA(z);
};
C.prototype.SA = function (w) {
	var z = w.parentObject;
	for (var i = 0; i < z.aE; i++) {
		if (z.childNodes[i] == w) {
			return i;
		}
	}
};
C.prototype.rH = function (node) {
	if ((node) && (node.tA)) {
		node.span.className = "standartTreeRow";
		if (node.kP) {
			node.span.style.color = node.kP;
		}
		node.tA = false;
		for (var i = 0; i < this._selected.length; i++) {
			if (!this._selected[i].tA) {
				this._selected.splice(i, 1);
				break;
			}
		}
	}
};
C.prototype.Fo = function () {
	for (var i = 0; i < this._selected.length; i++) {
		var node = this._selected[i];
		node.span.className = "standartTreeRow";
		if (node.kP) {
			node.span.style.color = node.kP;
		}
		node.tA = false;
	}
	this._selected = new Array();
};
C.prototype.onRowSelect = function (e, aI, mode) {
	e = e || window.event;
	var obj = this.parentObject;
	if (aI) {
		obj = aI.parentObject;
	}
	var that = obj.treeNod;
	var adi = that.ah();
	if ((!e) || (!e.adQ)) {
		that.yM(obj, e);
	}
	if (!mode) {
		if (obj.eP) {
			obj.eP(obj.id, adi);
		} else {
			that.callEvent("onClick", [obj.id, adi]);
		}
	}
};
C.prototype.gU = function (Ll) {
	if (!this.tO) {
		return;
	}
	if (!Ll) {
		return;
	}
	if (Ll.id == this.fO) {
		return;
	}
	var act = Ll.childNodes;
	var UL = 0;
	var abQ = 0;
	if (Ll.aE == 0) {
		return;
	}
	for (var i = 0; i < Ll.aE; i++) {
		if (act[i].vO) {
			continue;
		}
		if (act[i].cY == 0) {
			UL = 1;
		} else {
			if (act[i].cY == 1) {
				abQ = 1;
			} else {
				UL = 1;
				abQ = 1;
				break;
			}
		}
	}
	if ((UL) && (abQ)) {
		this.bL(Ll, "unsure");
	} else {
		if (UL) {
			this.bL(Ll, false);
		} else {
			this.bL(Ll, true);
		}
	}
	this.gU(Ll.parentObject);
};
C.prototype.DT = function (e) {
	if (!this.treeNod.callEvent("onBeforeCheck", [this.parentObject.id, this.parentObject.cY])) {
		return;
	}
	if (this.parentObject.vO) {
		return true;
	}
	if (this.treeNod.tO) {
		if (this.parentObject.cY == 1) {
			this.treeNod.iE(false, this.parentObject);
		} else {
			this.treeNod.iE(true, this.parentObject);
		}
	} else {
		if (this.parentObject.cY == 1) {
			this.treeNod.bL(this.parentObject, false);
		} else {
			this.treeNod.bL(this.parentObject, true);
		}
	}
	this.treeNod.gU(this.parentObject.parentObject);
	return this.treeNod.callEvent("onCheck", [this.parentObject.id, this.parentObject.cY]);
};
C.prototype.ux = function (acheck, aa, mode) {

	var table = document.createElement("table");
	table.cellSpacing = 0;
	table.cellPadding = 0;
	table.border = 0;
	if (this.acX) {
		table.style.tableLayout = "fixed";
	}
	table.style.margin = 0;
	table.style.padding = 0;
	var tbody = document.createElement("tbody");
	var tr = document.createElement("tr");
	var xp = document.createElement("td");
	xp.className = "standartTreeImage";
	if (this.Lu) {
		var CD = document.createElement("div");
		xp.appendChild(CD);
		CD.className = "dhx_tree_textSign";
	} else {
		var CD = this.Lg(aa.id);
		CD.border = "0";
		if (CD.tagName == "IMG") {
			CD.align = "absmiddle";
		}
		xp.appendChild(CD);
		CD.style.padding = 0;
		CD.style.margin = 0;
		CD.style.width = this.Rr;
		CD.style.height = this.QQ;
	}
	var abR = document.createElement("td");
	var inp = this.Lg(this.ahe ? this.fO : aa.id);
	inp.checked = 0;
	this.Rx(inp, this.mF + this.Bq[0]);
	inp.style.width = "16px";
	inp.style.height = "16px";
	if (!acheck) {
		((!_isIE) ? abR : inp).style.display = "none";
	}
	abR.appendChild(inp);
	if ((!this.ahe) && (inp.tagName == "IMG")) {
		inp.align = "absmiddle";
	}
	inp.onclick = this.DT;
	inp.treeNod = this;
	inp.parentObject = aa;
	if (!window._KHTMLrv) {
		abR.width = "20px";
	} else {
		abR.width = "16px";
	}
	var Rm = document.createElement("td");
	Rm.className = "standartTreeImage";
	var img = this.Lg(this.We ? aa.id : this.fO);
	img.onmousedown = this.kY;
	img.ondragstart = this.kY;
	img.border = "0";
	if (this.Jm) {
		img.parentObject = aa;
		if (img.tagName == "IMG") {
			img.align = "absmiddle";
		}
		img.onclick = this.onRowSelect;
	}
	if (!mode) {
		this.Rx(img, this.iconURL + this.gZ[0]);
	}
	Rm.appendChild(img);
	img.style.padding = 0;
	img.style.margin = 0;
	if (this.We) {
		Rm.style.width = img.style.width = this.ST;
		img.style.height = this.SR;
	} else {
		img.style.width = "0px";
		img.style.height = "0px";
		if (cU) {
			Rm.style.display = "none";
		}
	}
	
	
	var Bb = document.createElement("td");
	Bb.className = "standartTreeRow";
	aa.span = document.createElement("span");
	aa.span.className = "standartTreeRow";
	if (this.Li) {
		aa.span.style.width = this.Li;
		aa.span.style.display = "block";
	} else {
		Bb.noWrap = true;
	}
	if (_isIE && _isIE > 7) {
		Bb.style.width = "999999px";
	} else {
		if (!window._KHTMLrv) {
			Bb.style.width = "100%";
		}
	}
	aa.span.innerHTML = aa.label;
	Bb.appendChild(aa.span);
	Bb.parentObject = aa;
	xp.parentObject = aa;
	Bb.onclick = this.onRowSelect;
	xp.onclick = this.PR;
	Bb.ondblclick = this.Mk;
	
	if (this.anL) {
		tr.title = aa.label;
	}
	if (this.nz) {
		if (this.Jm) {
			this.M.dS(Rm, this);
			Rm.parentObject = aa;
		}
		this.M.dS(Bb, this);
	}
	aa.span.style.paddingLeft = "5px";
	aa.span.style.paddingRight = "5px";
	Bb.style.verticalAlign = "";
	Bb.style.fontSize = "10pt";
	Bb.style.cursor = this.Id;
	tr.appendChild(xp);
	tr.appendChild(abR);
	tr.appendChild(Rm);
	tr.appendChild(Bb);
	tbody.appendChild(tr);
	table.appendChild(tbody);

	if (this.WG || this.mR("onMouseIn") || this.mR("onMouseOut")) {
		tr.onmousemove = this.Jf;
		tr[(_isIE) ? "onmouseleave" : "onmouseout"] = this.It;
	}
	return table;
};
C.prototype.setImagePath = function (aiO) {
	this.mF = aiO;
	this.iconURL = aiO;
};
C.prototype.setIconPath = function (path) {
	this.iconURL = path;
};
C.prototype.As = function (at) {
	var a = 0;
	for (var b = 0; b < at.aE; b++) {
		if (at.childNodes[b].aE == 0) {
			a++;
		}
	}
	return a;
};
C.prototype.Zd = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	if ((AT.bZ) || ((!AT.fS) && (this.fs))) {
		return AT.ph;
	}
	switch (this.fo) {
	  case 1:
		return AT.aE;
		break;
	  case 2:
		return this.As(AT);
		break;
	  case 3:
		return AT.ph;
		break;
	  case 4:
		return AT.ph;
		break;
	}
};
C.prototype.fH = function (at, index) {
	if (this.fo == null) {
		return;
	}
	if ((at.bZ) || ((!at.fS) && (this.fs))) {
		if (at.ph) {
			at.span.innerHTML = at.label + this.sP + at.ph + this.htmlcB;
		} else {
			at.span.innerHTML = at.label;
		}
		return;
	}
	switch (this.fo) {
	  case 1:
		if (at.aE != 0) {
			at.span.innerHTML = at.label + this.sP + at.aE + this.htmlcB;
		} else {
			at.span.innerHTML = at.label;
		}
		break;
	  case 2:
		var z = this.As(at);
		if (z != 0) {
			at.span.innerHTML = at.label + this.sP + z + this.htmlcB;
		} else {
			at.span.innerHTML = at.label;
		}
		break;
	  case 3:
		if (at.aE != 0) {
			var Tv = 0;
			for (var a = 0; a < at.aE; a++) {
				if (!at.childNodes[a].ph) {
					at.childNodes[a].ph = 0;
				}
				Tv += at.childNodes[a].ph * 1;
			}
			Tv += at.aE * 1;
			at.span.innerHTML = at.label + this.sP + Tv + this.htmlcB;
			at.ph = Tv;
		} else {
			at.span.innerHTML = at.label;
			at.ph = 0;
		}
		if ((at.parentObject) && (at.parentObject != this.ao)) {
			this.fH(at.parentObject);
		}
		break;
	  case 4:
		if (at.aE != 0) {
			var Tv = 0;
			for (var a = 0; a < at.aE; a++) {
				if (!at.childNodes[a].ph) {
					at.childNodes[a].ph = 1;
				}
				Tv += at.childNodes[a].ph * 1;
			}
			at.span.innerHTML = at.label + this.sP + Tv + this.htmlcB;
			at.ph = Tv;
		} else {
			at.span.innerHTML = at.label;
			at.ph = 1;
		}
		if ((at.parentObject) && (at.parentObject != this.ao)) {
			this.fH(at.parentObject);
		}
		break;
	}
};
C.prototype.Cn = function (mode) {
	switch (mode) {
	  case "child":
		this.fo = 1;
		break;
	  case "leafs":
		this.fo = 2;
		break;
	  case "childrec":
		this.fo = 3;
		break;
	  case "leafsrec":
		this.fo = 4;
		break;
	  case "disabled":
		this.fo = null;
		break;
	  default:
		this.fo = 4;
	}
};
C.prototype.aeX = function (ang, anh) {
	this.sP = ang;
	this.htmlcB = anh;
};
C.prototype.Fa = function (aQ) {
	this.attachEvent("onRightClick", aQ);
};
C.prototype.ck = function (aQ) {
	this.attachEvent("onClick", aQ);
};
C.prototype.YD = function (aQ) {
	this.attachEvent("onSelect", aQ);
};
C.prototype.eG = function (bU) {
	this.fs = bU;
};
C.prototype.uq = function (aQ) {
	this.attachEvent("onCheck", aQ);
};
C.prototype.Ng = function (aQ) {
	this.attachEvent("onOpenStart", aQ);
};
C.prototype.Gm = function (aQ) {
	this.attachEvent("onOpenStart", aQ);
};
C.prototype.rV = function (aQ) {
	this.attachEvent("onOpenEnd", aQ);
};
C.prototype.mY = function (aQ) {
	this.attachEvent("onDblClick", aQ);
};
C.prototype.Jo = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	this.SP(AT);
};
C.prototype.KL = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return "";
	}
	return this.dD(AT);
};
C.prototype.AA = function (itemId) {
	if (itemId === window.undefined) {
		itemId = this.fO;
	}
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	this.Ho(AT);
	this.cB.childNodes[0].border = "1";
	this.cB.childNodes[0].border = "0";
};
C.prototype.setUserData = function (itemId, name, value) {
	var aX = this.ak(itemId, 0, true);
	if (!aX) {
		return;
	}
	if (name == "hint") {
		aX.ao.childNodes[0].childNodes[0].title = value;
	}
//	alert(itemId + ":" + name +" = "+value);
	if (typeof (aX.userData["t_" + name]) == "undefined") {
		if (!aX.PJ) {
			aX.PJ = name;
		} else {
			aX.PJ += "," + name;
		}
	}
	aX.userData["t_" + name] = value;
};
C.prototype.getUserData = function (itemId, name) {
	var aX = this.ak(itemId, 0, true);
	if (!aX) {
		return;
	}
	return aX.userData["t_" + name];
};
C.prototype.akk = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	var res = new Object();
	if (AT.kP) {
		res.kP = AT.kP;
	}
	if (AT.mB) {
		res.mB = AT.mB;
	}
	return res;
};
C.prototype.lF = function (itemId, wo, vf) {
	if ((itemId) && (itemId.span)) {
		var AT = itemId;
	} else {
		var AT = this.ak(itemId);
	}
	if (!AT) {
		return 0;
	} else {
		if (AT.tA) {
			if (vf) {
				AT.span.style.color = vf;
			}
		} else {
			if (wo) {
				AT.span.style.color = wo;
			}
		}
		if (vf) {
			AT.mB = vf;
		}
		if (wo) {
			AT.kP = wo;
		}
	}
};
C.prototype.getItemText = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	return (AT.ao.childNodes[0].childNodes[0].childNodes[3].childNodes[0].innerHTML);
};
C.prototype.getParentId = function (itemId) {
	var AT = this.ak(itemId);
	if ((!AT) || (!AT.parentObject)) {
		return "";
	}
	return AT.parentObject.id;
};
C.prototype.changeItemId = function (itemId, fW) {
	if (itemId == fW) {
		return;
	}
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	AT.id = fW;
	AT.span.contextMenuId = fW;
	this.gQ[fW] = this.gQ[itemId];
	delete this.gQ[itemId];
};
C.prototype.anS = function () {
	if (this.rN) {
		this.Xd();
	}
	this.rN = (new Array()).concat(this._selected);
	for (var i = 0; i < this.rN.length; i++) {
		var mN = this.rN[i];
		mN.FH = new Array();
		mN.FH[0] = mN.images[0];
		mN.FH[1] = mN.images[1];
		mN.FH[2] = mN.images[2];
		mN.images[0] = mN.images[1] = mN.images[2] = this.agE;
		this.cE(mN);
	}
};
C.prototype.ajr = function (itemId) {
	var tobj = this.ak(itemId);
	if (!tobj) {
		return 0;
	}
	for (var i = 0; i < this.rN.length; i++) {
		if (this.wj(tobj, this.rN[i])) {
			continue;
		}
		this.SO(this.rN[i], tobj);
	}
	this.Xd();
};
C.prototype.Xd = function () {
	for (var i = 0; i < this.rN.length; i++) {
		var mN = this.rN[i];
		mN.images[0] = mN.FH[0];
		mN.images[1] = mN.FH[1];
		mN.images[2] = mN.FH[2];
		this.cE(mN);
	}
	this.rN = new Array();
};
C.prototype.SO = function (aa, bn) {
	var mode = this.ll;
	if (mode == 1) {
		var z = bn;
		if (this.mW < 0) {
			while (true) {
				z = this.pR(z);
				if ((z == -1)) {
					z = this.ao;
					break;
				}
				if ((z.tr == 0) || (z.tr.style.display == "") || (!z.parentObject)) {
					break;
				}
			}
			var abe = z;
			var HU = bn;
		} else {
			while (true) {
				z = this.ob(z);
				if ((z == -1)) {
					z = this.ao;
					break;
				}
				if ((z.tr.style.display == "") || (!z.parentObject)) {
					break;
				}
			}
			var HU = z;
			var abe = bn;
		}
		if (this.uU(abe, 0) > this.uU(HU, 0)) {
			if (!this.aep) {
				return this.fJ(aa, abe.parentObject);
			} else {
				if (HU.id != this.fO) {
					return this.fJ(aa, HU.parentObject, HU);
				} else {
					return this.fJ(aa, this.ao, null);
				}
			}
		} else {
			return this.fJ(aa, HU.parentObject, HU);
		}
	} else {
		return this.fJ(aa, bn);
	}
};
C.prototype.xE = function (target, ZC) {
	var mt = 0;
	var ari = 0;
	var dN = target.childNodes;
	var Count = target.aE - 1;
	if (ZC == dN[Count]) {
		return;
	}
	for (var i = 0; i < Count; i++) {
		if (dN[i] == dN[Count]) {
			dN[i] = dN[i + 1];
			dN[i + 1] = dN[Count];
		}
	}
	for (var i = 0; i < Count + 1; i++) {
		if (mt) {
			var AT = dN[i];
			dN[i] = mt;
			mt = AT;
		} else {
			if (dN[i] == ZC) {
				mt = dN[i];
				dN[i] = dN[Count];
			}
		}
	}
};
C.prototype.DL = function (aa, bn, bT, gR) {
	var i;
	var st = "";
	if (bT) {
		for (i = 0; i < bn.aE; i++) {
			if (bn.childNodes[i] == bT) {
				break;
			}
		}
		if (i != 0) {
			bT = bn.childNodes[i - 1];
		} else {
			st = "TOP";
			bT = "";
		}
	}
	var arM = this.BX;
	this.BX = null;
	var fi = this.kV(bn, aa.id, aa.label, 0, aa.images[0], aa.images[1], aa.images[2], st, 0, bT);
	fi.PJ = aa.PJ;
	fi.userData = aa.userData.QF();
	fi.fS = aa.fS;
	if (arM) {
		this.BX = arM;
		this.BX(fi.id);
	}
	if (aa.treeNod.BM) {
		aa.treeNod.ak(aa.id);
	} else {
		fi.bZ = aa.bZ;
	}
	this.cE(fi);
	for (var i = 0; i < aa.aE; i++) {
		this.DL(aa.childNodes[i], fi, 0, 1);
	}
	if ((!gR) && (this.fo)) {
		this.jm(this, bn);
	}
	return fi;
};
C.prototype.fJ = function (aa, bn, bT) {
	if (aa.treeNod.oy) {
		return aa.treeNod.oy(this, bn, bT, aa);
	}
	if (bn.acE) {
		var Bn = (aa.treeNod.Rs != bn.Rs);
	} else {
		var Bn = (aa.treeNod.Rs != bn.treeNod.Rs);
	}
	if (!this.callEvent("onDrag", [aa.id, bn.id, (bT ? bT.id : null), aa.treeNod, bn.treeNod])) {
		return false;
	}
	if ((bn.fS == 0) && (this.fs)) {
		bn.fS = 1;
		this.pA(bn.id);
	}
	this.hx(bn.id);
	var hP = aa.treeNod;
	var c = aa.parentObject.aE;
	var z = aa.parentObject;
	if ((Bn) || (hP.BM)) {
		var alp = aa.id;
		aa = this.DL(aa, bn, bT);
		if (!hP.BM) {
			hP.deleteItem(alp);
		}
	} else {
		var Count = bn.aE;
		var dN = bn.childNodes;
		if (Count == 0) {
			bn.ahl = true;
		}
		hP.rH(aa);
		dN[Count] = aa;
		aa.treeNod = bn.treeNod;
		bn.aE++;
		var tr = this.YT(dN[Count].ao);
		if (!bT) {
			bn.ao.childNodes[0].appendChild(tr);
			if (this.mj == 1) {
				this.xE(bn, bT);
			}
		} else {
			bn.ao.childNodes[0].insertBefore(tr, bT.tr);
			this.xE(bn, bT);
			dN = bn.childNodes;
		}
	}
	if ((!hP.BM) && (!Bn)) {
		var aow = aa.tr;
		if ((document.all) && (navigator.appVersion.search(/MSIE\ 5\.0/gi) != -1)) {
			window.setTimeout(function () {
				aow.parentNode.removeChild(aow);
			}, 250);
		} else {
			aa.parentObject.ao.childNodes[0].removeChild(aa.tr);
		}
		if ((!bT) || (bn != aa.parentObject)) {
			for (var i = 0; i < z.aE; i++) {
				if (z.childNodes[i].id == aa.id) {
					z.childNodes[i] = 0;
					break;
				}
			}
		} else {
			z.childNodes[z.aE - 1] = 0;
		}
		hP.Ak(z.aE, z.childNodes);
		z.aE--;
	}
	if ((!Bn) && (!hP.BM)) {
		aa.tr = tr;
		tr.mX = aa;
		aa.parentObject = bn;
		if (hP != bn.treeNod) {
			if (aa.treeNod.DZ(aa, hP)) {
				return;
			}
			this.Ks(aa);
			this.jm(this, aa.parentObject);
		}
		this.cE(bn);
		this.gK(bn);
		this.gK(aa);
		this.cE(aa);
		if (bT) {
			this.cE(bT);
		} else {
			if (bn.aE >= 2) {
				this.cE(dN[bn.aE - 2]);
				this.gK(dN[bn.aE - 2]);
			}
		}
		this.cE(dN[bn.aE - 1]);
		if (this.tO) {
			this.gU(bn);
		}
		if (hP.tO) {
			hP.gU(z);
		}
	}
	if (c > 1) {
		hP.cE(z.childNodes[c - 2]);
		hP.gK(z.childNodes[c - 2]);
	}
	hP.cE(z);
	hP.gK(z);
	this.fH(bn);
	hP.fH(z);
	this.callEvent("onDrop", [aa.id, bn.id, (bT ? bT.id : null), hP, bn.treeNod]);
	return aa.id;
};
C.prototype.Ks = function (aa) {
	if (!aa.ao) {
		return;
	}
	var xp = aa.ao.childNodes[0].childNodes[0].childNodes[1];
	var ade = xp.nextSibling.nextSibling;
	aa.span.innerHTML = aa.label;
	aa.tA = false;
	if (aa.Jm) {
		this.M.fG(xp.nextSibling);
	}
	if (this.ps) {
		xp.childNodes[0].style.display = "";
		xp.childNodes[0].onclick = this.DT;
		this.Rx(xp.childNodes[0], this.mF + this.Bq[aa.cY]);
	} else {
		xp.childNodes[0].style.display = "none";
	}
	xp.childNodes[0].treeNod = this;
	this.M.fG(ade);
	if (this.nz) {
		this.M.dS(ade, this);
	}
	if (this.Jm) {
		this.M.dS(xp.nextSibling, this);
	}
	ade.childNodes[0].className = "standartTreeRow";
	ade.onclick = this.onRowSelect;
	ade.ondblclick = this.Mk;
	xp.previousSibling.onclick = this.PR;
	this.gK(aa);
	this.cE(aa);
	for (var i = 0; i < aa.aE; i++) {
		this.Ks(aa.childNodes[i]);
	}
};
C.prototype.DZ = function (aa, hP) {
	if (hP) {
		hP.rW(aa.id);
	}
	aa.id = this.oh(aa.id, aa);
	aa.treeNod = this;
	for (var i = 0; i < aa.aE; i++) {
		this.DZ(aa.childNodes[i], hP);
	}
	return 0;
};
C.prototype.enableThreeStateCheckboxes = function (mode) {
	this.tO = K(mode);
};
C.prototype.acp = function (aQ) {
	this.WG = true;
	this.attachEvent("onMouseIn", aQ);
};
C.prototype.aaE = function (aQ) {
	this.WG = true;
	this.attachEvent("onMouseOut", aQ);
};
C.prototype.enableMercyDrag = function (mode) {
	this.BM = K(mode);
};
C.prototype.enableTreeImages = function (mode) {
	this.We = K(mode);
};
C.prototype.ahS = function (mode) {
	this.acX = K(mode);
};
C.prototype.enableCheckBoxes = function (mode, hidden) {
	this.ps = K(mode);
	this.ahe = (!(this.ps || K(hidden)));
};
C.prototype.ss = function (kQ, kS, nI) {
	this.gZ[0] = kQ;
	this.gZ[1] = kS;
	this.gZ[2] = nI;
};
C.prototype.enableTreeLines = function (mode) {
	this.Fc = K(mode);
};
C.prototype.hQ = function (acL, kQ, kS, nI, aes, aeq) {
	switch (acL) {
	  case "plus":
		this.nj[0] = kQ;
		this.nj[1] = kS;
		this.nj[2] = nI;
		this.nj[3] = aes;
		this.nj[4] = aeq;
		break;
	  case "minus":
		this.mQ[0] = kQ;
		this.mQ[1] = kS;
		this.mQ[2] = nI;
		this.mQ[3] = aes;
		this.mQ[4] = aeq;
		break;
	}
};
C.prototype.hx = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	} else {
		return this.nk(AT);
	}
};
C.prototype.nk = function (item) {
	var state = this.dD(item);
	if ((state < 0) || (((this.fs) && (!item.fS)))) {
		if (!this.callEvent("onOpenStart", [item.id, state])) {
			return 0;
		}
		this.kK(item, 2);
		if (this.mR("onOpenEnd")) {
			if (this.onXLE == this.FW) {
				this.FW(this, item.id, true);
			}
			if (!this.ku || !this.fs) {
				this.callEvent("onOpenEnd", [item.id, this.dD(item)]);
			} else {
				this.HM.push(this.onXLE);
				this.onXLE = this.FW;
			}
		}
	} else {
		if (this.ahK) {
			this.kK(item, 2);
		}
	}
	if (item.parentObject && !this._skip_open_parent) {
		this.nk(item.parentObject);
	}
};
C.prototype.KW = function (itemId) {
	if (this.fO == itemId) {
		return 0;
	}
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	if (AT.ro) {
		this.kK(AT, 1);
	}
};
C.prototype.sS = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	return this.uU(AT, 0);
};
C.prototype.Cq = function (itemId, mt) {
	mt = K(mt);
	if ((itemId) && (itemId.span)) {
		var AT = itemId;
	} else {
		var AT = this.ak(itemId);
	}
	if (!AT) {
		return 0;
	}
	AT.ro = mt;
};
C.prototype.uU = function (aa, count) {
	if (aa.parentObject) {
		return this.uU(aa.parentObject, count + 1);
	}
	return (count);
};
C.prototype.MD = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	} else {
		if ((this.fs) && (!AT.fS)) {
			return true;
		} else {
			return AT.aE;
		}
	}
};
C.prototype.As = function (at) {
	var a = 0;
	for (var b = 0; b < at.aE; b++) {
		if (at.childNodes[b].aE == 0) {
			a++;
		}
	}
	return a;
};
C.prototype.setItemText = function (itemId, VK, OS) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	AT.label = VK;
	AT.span.innerHTML = VK;
	if (this.fo) {
		this.fH(AT);
	}
	AT.span.parentNode.parentNode.title = OS || "";
};
C.prototype.aiv = function (itemId) {
	var AT = this.ak(itemId);
	if (!AT) {
		return "";
	}
	return (AT.span.parentNode.parentNode.aob || AT.span.parentNode.parentNode.title || "");
};
C.prototype.uL = function (itemId) {
	if (!itemId) {
		itemId = this.fO;
	}
	var AT = this.ak(itemId);
	this.fa(itemId);
	this.pA(itemId);
};
C.prototype.dC = function (itemId, kQ, kS, nI) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	AT.images[1] = kS;
	AT.images[2] = nI;
	AT.images[0] = kQ;
	this.cE(AT);
};
C.prototype.setItemImage = function (itemId, kQ, kS) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	if (kS) {
		AT.images[1] = kQ;
		AT.images[2] = kS;
	} else {
		AT.images[0] = kQ;
	}
	this.cE(AT);
};
C.prototype.Mn = function (itemId) {
	var AT = this.ak(itemId, 0, 1);
	if (!AT) {
		return 0;
	}
	if (AT.bZ) {
		return (this.Qo(AT.bZ));
	}
	var z = "";
	for (i = 0; i < AT.aE; i++) {
		if (!z) {
			z = AT.childNodes[i].id;
		} else {
			z += this.jB + AT.childNodes[i].id;
		}
	}
	return z;
};
C.prototype.oi = function (node) {
	var z = "";
	for (var i = 0; i < node.aE; i++) {
		if ((node.childNodes[i].bZ) || (node.childNodes[i].aE > 0)) {
			if (node.childNodes[i].bZ) {
				var zb = this.uD(node.childNodes[i].bZ, 1);
			} else {
				var zb = this.oi(node.childNodes[i]);
			}
			if (zb) {
				if (z) {
					z += this.jB + zb;
				} else {
					z = zb;
				}
			}
		} else {
			if (!z) {
				z = node.childNodes[i].id;
			} else {
				z += this.jB + node.childNodes[i].id;
			}
		}
	}
	return z;
};
C.prototype.sj = function (node) {
	var z = "";
	for (var i = 0; i < node.aE; i++) {
		if ((node.childNodes[i].bZ) || (node.childNodes[i].aE > 0)) {
			if (!z) {
				z = node.childNodes[i].id;
			} else {
				z += this.jB + node.childNodes[i].id;
			}
			if (node.childNodes[i].bZ) {
				var zb = this.zW(node.childNodes[i].bZ, 1);
			} else {
				var zb = this.sj(node.childNodes[i]);
			}
			if (zb) {
				z += this.jB + zb;
			}
		}
	}
	return z;
};
C.prototype.DK = function (itemId, z, node) {
	if (node) {
		AT = node;
	} else {
		var AT = this.ak(itemId);
	}
	if (!AT) {
		return 0;
	}
	z = "";
	for (var i = 0; i < AT.aE; i++) {
		if (!z) {
			z = AT.childNodes[i].id;
		} else {
			z += this.jB + AT.childNodes[i].id;
		}
		var zb = this.DK(0, z, AT.childNodes[i]);
		if (zb) {
			z += this.jB + zb;
		}
	}
	if (AT.bZ) {
		z = this.Ku(itemId, z, AT.bZ);
	}
	return z;
};
C.prototype.hE = function (itemId, mode, iW) {
	mode = K(mode);
	var AT = this.ak(itemId);
	if ((!AT) || (!AT.parentObject)) {
		return 0;
	}
	if (this.ek) {
		AT.parentObject.Xm = 1;
	} else {
		this.nk(AT.parentObject);
	}
	var ze = null;
	if (iW) {
		ze = new Object;
		ze.ctrlKey = true;
		if (AT.tA) {
			ze.adQ = true;
		}
	}
	if (mode) {
		this.onRowSelect(ze, AT.ao.childNodes[0].childNodes[0].childNodes[3], false);
	} else {
		this.onRowSelect(ze, AT.ao.childNodes[0].childNodes[0].childNodes[3], true);
	}
};
C.prototype.xB = function () {
	var str = new Array();
	for (var i = 0; i < this._selected.length; i++) {
		str[i] = this._selected[i].span.innerHTML;
	}
	return (str.join(this.jB));
};
C.prototype.Ak = function (Count, dN) {
	Count--;
	for (var i = 0; i < Count; i++) {
		if (dN[i] == 0) {
			dN[i] = dN[i + 1];
			dN[i + 1] = 0;
		}
	}
};
C.prototype.My = function (itemId, aI, Ch) {
	if ((!aI) || (!aI.parentObject)) {
		return 0;
	}
	var PQ = 0;
	var Ls = 0;
	if (aI.tr.nextSibling) {
		PQ = aI.tr.nextSibling.mX;
	}
	if (aI.tr.previousSibling) {
		Ls = aI.tr.previousSibling.mX;
	}
	var sN = aI.parentObject;
	var Count = sN.aE;
	var dN = sN.childNodes;
	for (var i = 0; i < Count; i++) {
		if (dN[i].id == itemId) {
			if (!Ch) {
				sN.ao.childNodes[0].removeChild(dN[i].tr);
			}
			dN[i] = 0;
			break;
		}
	}
	this.Ak(Count, dN);
	if (!Ch) {
		sN.aE--;
	}
	if (PQ) {
		this.cE(PQ);
		this.gK(PQ);
	}
	if (Ls) {
		this.cE(Ls);
		this.gK(Ls);
	}
	if (this.tO) {
		this.gU(sN);
	}
	if (!Ch) {
		this.us(aI);
	}
};
C.prototype.mA = function (itemId, state) {
	var aX = this.ak(itemId, 0, 1);
	if (!aX) {
		return;
	}
	if (state === "unsure") {
		this.bL(aX, state);
	} else {
		state = K(state);
		if ((this.tO) && (this.xL)) {
			this.iE(state, aX);
		} else {
			this.bL(aX, state);
		}
	}
	if (this.xL) {
		this.gU(aX.parentObject);
	}
};
C.prototype.bL = function (aX, state) {
	if (!aX) {
		return;
	}
	if (((aX.parentObject.nN) || (this.Co)) && (state)) {
		if (this.aih) {
			if (this.Zk) {
				this.mA(this.Zk.id, 0);
			}
			this.Zk = aX;
		} else {
			for (var i = 0; i < aX.parentObject.aE; i++) {
				this.bL(aX.parentObject.childNodes[i], 0);
			}
		}
	}
	var z = aX.ao.childNodes[0].childNodes[0].childNodes[1].childNodes[0];
	if (state == "unsure") {
		aX.cY = 2;
	} else {
		if (state) {
			aX.cY = 1;
		} else {
			aX.cY = 0;
		}
	}
	if (aX.vO) {
		aX.cY = aX.vO;
	}
	this.Rx(z, this.mF + ((aX.parentObject.nN || this.Co) ? this.GR : this.Bq)[aX.cY]);
};
C.prototype.vh = function (itemId, state) {
	var aX = this.ak(itemId);
	this.iE(state, aX);
	this.gU(aX.parentObject);
};
C.prototype.iE = function (state, aX) {
	state = K(state);
	if (!aX) {
		return;
	}
	if (((aX.parentObject.nN) || (this.Co)) && (state)) {
		for (var i = 0; i < aX.parentObject.aE; i++) {
			this.iE(0, aX.parentObject.childNodes[i]);
		}
	}
	if (aX.bZ) {
		this.LT(state, aX.bZ);
	}
	if (aX.nN || this.Co) {
		this.iE(state, aX.childNodes[0]);
	} else {
		for (var i = 0; i < aX.aE; i++) {
			this.iE(state, aX.childNodes[i]);
		}
	}
	var z = aX.ao.childNodes[0].childNodes[0].childNodes[1].childNodes[0];
	if (state) {
		aX.cY = 1;
	} else {
		aX.cY = 0;
	}
	if (aX.vO) {
		aX.cY = aX.vO;
	}
	this.Rx(z, this.mF + ((aX.parentObject.nN || this.Co) ? this.GR : this.Bq)[aX.cY]);
};
C.prototype.ajT = function (itemId) {
	var aX = this.ak(itemId);
	if (!aX) {
		return;
	}
	return aX.cY;
};
C.prototype.fa = function (itemId) {
	var aX = this.ak(itemId);
	if (!aX) {
		return;
	}
	var j = aX.aE;
	for (var i = 0; i < j; i++) {
		this.My(aX.childNodes[0].id, aX.childNodes[0]);
	}
};
C.prototype.deleteItem = function (itemId, tu) {
	if ((!this.ajc) || (this.ajc(itemId))) {
		var z = this.XO(itemId, tu);
		this.fH(z);
	}
	this.cB.childNodes[0].border = "1";
	this.cB.childNodes[0].border = "0";
};
C.prototype.XO = function (itemId, tu, Ch) {
	tu = K(tu);
	var aX = this.ak(itemId);
	if (!aX) {
		return;
	}
	var qc = this.getParentId(itemId);
	var ZV = aX.parentObject;
	this.My(itemId, aX, Ch);
	this.cE(ZV);
	this.gK(ZV);
	if ((tu) && (qc != this.fO)) {
		this.hE(qc, 1);
	}
	return ZV;
};
C.prototype.us = function (aa) {
	for (var i = 0; i < aa.aE; i++) {
		this.us(aa.childNodes[i]);
		this.rW(aa.childNodes[i].id);
	}
	this.rW(aa.id);
	var z = aa;
	z.span = null;
	z.tr.mX = null;
	z.tr = null;
	z.ao = null;
};
C.prototype.insertNewNext = function (itemId, fW, itemText, kA, kQ, kS, nI, kC, children) {
	var aX = this.ak(itemId);
	if ((!aX) || (!aX.parentObject)) {
		return (0);
	}
	var aaN = this.kV(0, fW, itemText, kA, kQ, kS, nI, kC, children, aX);
	if ((!this.ek) && (this.fo)) {
		this.fH(aX.parentObject);
	}
	return aaN;
};
C.prototype.afD = function (itemId, index) {
	var z = this.ak(itemId);
	if ((!z) || (index >= z.aE)) {
		return null;
	}
	return z.childNodes[index].id;
};
C.prototype.FI = function (itemId, index) {
	var z = this.ak(itemId);
	if ((!z) || (index >= z.aE)) {
		return null;
	}
	return z.childNodes[index].id;
};
C.prototype.lh = function (aQ) {
	this.attachEvent("onDrag", aQ);
};
C.prototype.mH = function () {
	if (this.Ed) {
		this.Ed.className = this.Ed.className.replace(/dragAndDropRow/g, "");
		this.Ed = null;
	}
	this.selectionBar.style.display = "none";
	this.cB.className = this.cB.className.replace(" selectionBox", "");
};
C.prototype.enableDragAndDrop = function (mode, rmode) {
	if (mode == "temporary_disabled") {
		this.ko = false;
		mode = true;
	} else {
		this.ko = true;
	}
	this.nz = K(mode);
	if (this.nz) {
		this.M.eH(this.cB, this);
	}
	if (arguments.length > 1) {
		this.ajC = (!K(rmode));
	}
};
C.prototype.VN = function (ao, x, y) {
	if (ao.parentObject.span) {
		var a1 = dg(ao);
		var a2 = dg(this.cB);
		this.ll = this.mj;
		this.mW = 0;
		if (this.mj == 2) {
			var z = y - a1 + this.cB.scrollTop + (document.body.scrollTop || document.documentElement.scrollTop) - 2 - ao.offsetHeight / 2;
			if ((Math.abs(z) - ao.offsetHeight / 6) > 0) {
				this.ll = 1;
				if (z < 0) {
					this.mW = 0 - ao.offsetHeight;
				}
			} else {
				this.ll = 0;
			}
		}
		if (this.ll == 0) {
			var zN = ao.parentObject.span;
			zN.className += " dragAndDropRow";
			this.Ed = zN;
		} else {
			this.mH();
			this.selectionBar.style.top = (a1 - a2 + ((parseInt(ao.parentObject.span.parentNode.previousSibling.childNodes[0].style.height) || 18) - 1) + this.mW) + "px";
			this.selectionBar.style.left = "5px";
			if (this.cB.offsetWidth > 20) {
				this.selectionBar.style.width = (this.cB.offsetWidth - (aq ? 30 : 25)) + "px";
			}
			this.selectionBar.style.display = "";
		}
		this.MC(null, a1, a2);
	}
};
C.prototype.MC = function (node, a1, a2) {
	if (this.PZ) {
		if (node) {
			a1 = dg(node);
			a2 = dg(this.cB);
		}
		if ((a1 - a2 - parseInt(this.cB.scrollTop)) > (parseInt(this.cB.offsetHeight) - 50)) {
			this.cB.scrollTop = parseInt(this.cB.scrollTop) + 20;
		}
		if ((a1 - a2) < (parseInt(this.cB.scrollTop) + 30)) {
			this.cB.scrollTop = parseInt(this.cB.scrollTop) - 20;
		}
	}
};
C.prototype.gL = function (aI, e) {
	if (!this.ko) {
		return null;
	}
	var obj = aI.parentObject;
	if (!this.callEvent("onBeforeDrag", [obj.id])) {
		return null;
	}
	if (!obj.tA) {
		this.yM(obj, e);
	}
	this.wb();
	var fj = document.createElement("div");
	var text = new Array();
	if (this.Xy) {
		for (var i = 0; i < this._selected.length; i++) {
			text[i] = "<table cellspacing='0' cellpadding='0'><tr><td><img width='18px' height='18px' src='" + this.YW(this._selected[i].span.parentNode.previousSibling.childNodes[0]) + "'></td><td>" + this._selected[i].span.innerHTML + "</td></tr></table>";
		}
	} else {
		text = this.xB().split(this.jB);
	}
	fj.innerHTML = text.join("");
	fj.style.position = "absolute";
	fj.className = "dragSpanDiv";
	this.jG = (new Array()).concat(this._selected);
	return fj;
};
C.prototype.QH = function (item) {
	var z = dg(item.ao) - dg(this.cB);
	if ((z > (this.cB.scrollTop + this.cB.offsetHeight - 30)) || (z < this.cB.scrollTop)) {
		this.cB.scrollTop = z;
	}
};
C.prototype.kY = function (e) {
	if ((e) && (e.preventDefault)) {
		e.preventDefault();
		return false;
	}
	return false;
};
C.prototype.BK = function (la, Ll, il) {
	if (this.hg) {
		clearTimeout(this.hg);
	}
	if (!il.parentObject) {
		il = this.ao.ao.childNodes[0].childNodes[0].childNodes[1].childNodes[0];
		this.ll = 0;
	}
	this.mH();
	var z = la.parentObject.treeNod;
	if ((z) && (z.mH)) {
		z.mH("");
	}
	if ((!this.MP) || (this.MP())) {
		if ((!z) || (!z.mH) || (!z.jG)) {
			var col = new Array(la.parentObject);
		} else {
			var col = z.jG;
		}
		var ZE = il.parentObject;
		for (var i = 0; i < col.length; i++) {
			var UI = this.SO(col[i], ZE);
			if ((this.ll) && (UI !== false)) {
				ZE = this.ak(UI, true, true);
			}
			if ((UI) && (!this.alG)) {
				this.hE(UI, 0, 1);
			}
		}
	}
	if (z) {
		z.jG = new Array();
	}
};
C.prototype.tY = function (aI, nq, x, y) {
	if (!this.ko) {
		return 0;
	}
	var abW = nq.parentObject;
	var tobj = aI.parentObject;
	if ((!tobj) && (this.ajC)) {
		return;
	}
	if (!this.callEvent("onDragIn", [abW.id, tobj ? tobj.id : null, abW.treeNod, this])) {
		if (tobj) {
			this.MC(aI);
		}
		return 0;
	}
	if (!tobj) {
		this.cB.className += " selectionBox";
	} else {
		if (abW.childNodes == null) {
			this.VN(aI, x, y);
			return aI;
		}
		var stree = abW.treeNod;
		for (var i = 0; i < stree.jG.length; i++) {
			if (this.wj(tobj, stree.jG[i])) {
				this.MC(aI);
				return 0;
			}
		}
		this.selectionBar.parentNode.removeChild(this.selectionBar);
		tobj.span.parentNode.appendChild(this.selectionBar);
		this.VN(aI, x, y);
		if (this.dD(tobj) <= 0) {
			this.EV = tobj.id;
			this.hg = window.setTimeout(new jP(this.AN, this), 1000);
		}
	}
	return aI;
};
C.prototype.AN = function (e, bG) {
	bG.hx(bG.EV);
};
C.prototype.iX = function (aI) {
	this.mH();
	if (this.hg) {
		clearTimeout(this.hg);
	}
};
C.prototype.ob = function (item, mode) {
	if ((!mode) && (item.aE)) {
		return item.childNodes[0];
	}
	if (item == this.ao) {
		return -1;
	}
	if ((item.tr) && (item.tr.nextSibling) && (item.tr.nextSibling.mX)) {
		return item.tr.nextSibling.mX;
	}
	return this.ob(item.parentObject, true);
};
C.prototype.qK = function (item) {
	if (item.aE) {
		return this.qK(item.childNodes[item.aE - 1]);
	} else {
		return item;
	}
};
C.prototype.pR = function (node, mode) {
	if ((node.tr) && (node.tr.previousSibling) && (node.tr.previousSibling.mX)) {
		return this.qK(node.tr.previousSibling.mX);
	}
	if (node.parentObject) {
		return node.parentObject;
	} else {
		return -1;
	}
};
C.prototype.GE = function (jU, direction, top) {
	var z = this.Cj(jU, direction, (top ? this.ao : null));
	if (z) {
		this.hE(z.id, true);
		this.QH(z);
		return z.id;
	} else {
		return null;
	}
};
C.prototype.aeM = function (jU, direction, top) {
	var z = this.Cj(jU, direction, (top ? this.ao : null));
	if (z) {
		return z.id;
	} else {
		return null;
	}
};
C.prototype.sy = function (node, Le, acU) {
	if (!node.childNodes && node.item) {
		return this.findStrInJSON(node, Le, acU);
	}
	for (var i = 0; i < node.childNodes.length; i++) {
		if (node.childNodes[i].nodeType == 1) {
			var z = node.childNodes[i].getAttribute(Le);
			if (!z && node.childNodes[i].tagName == "itemtext") {
				z = node.childNodes[i].firstChild.data;
			}
			if ((z) && (z.toLowerCase().search(acU) != -1)) {
				return true;
			}
			if (this.sy(node.childNodes[i], Le, acU)) {
				return true;
			}
		}
	}
	return false;
};
C.prototype.findStrInJSON = function (node, Le, acU) {
	for (var i = 0; i < node.item.length; i++) {
		var z = node.item[i].text;
		if ((z) && (z.toLowerCase().search(acU) != -1)) {
			return true;
		}
		if (this.item[i].item && this.findStrInJSON(node.item[i], Le, acU)) {
			return true;
		}
	}
	return false;
};
C.prototype.Cj = function (jU, direction, dK) {
	var jU = jU.replace(new RegExp("^( )+"), "").replace(new RegExp("( )+$"), "");
	jU = new RegExp(jU.replace(/([\?\*\+\\\[\]\(\)]{1})/gi, "\\$1").replace(/ /gi, ".*"), "gi");
	if (!dK) {
		dK = this._selected[0];
		if (!dK) {
			dK = this.ao;
		}
	}
	var An = dK;
	if (!direction) {
		if ((dK.bZ) && (this.sy(dK.bZ.d, "text", jU))) {
			this.tK(dK);
		}
		dK = this.ob(An);
		if (dK == -1) {
			dK = this.ao.childNodes[0];
		}
	} else {
		var z2 = this.pR(An);
		if (z2 == -1) {
			z2 = this.qK(this.ao);
		}
		if ((z2.bZ) && (this.sy(z2.bZ.d, "text", jU))) {
			this.tK(z2);
			dK = this.pR(An);
		} else {
			dK = z2;
		}
		if (dK == -1) {
			dK = this.qK(this.ao);
		}
	}
	while ((dK) && (dK != An)) {
		if ((dK.label) && (dK.label.search(jU) != -1)) {
			return (dK);
		}
		if (!direction) {
			if (dK == -1) {
				if (An == this.ao) {
					break;
				}
				dK = this.ao.childNodes[0];
			}
			if ((dK.bZ) && (this.sy(dK.bZ.d, "text", jU))) {
				this.tK(dK);
			}
			dK = this.ob(dK);
			if (dK == -1) {
				dK = this.ao;
			}
		} else {
			var z2 = this.pR(dK);
			if (z2 == -1) {
				z2 = this.qK(this.ao);
			}
			if ((z2.bZ) && (this.sy(z2.bZ.d, "text", jU))) {
				this.tK(z2);
				dK = this.pR(dK);
			} else {
				dK = z2;
			}
			if (dK == -1) {
				dK = this.qK(this.ao);
			}
		}
	}
	return null;
};
C.prototype.moveItem = function (itemId, mode, CN, qH) {
	var aX = this.ak(itemId);
	if (!aX) {
		return (0);
	}
	switch (mode) {
	  case "right":
		alert("Not supported yet");
		break;
	  case "item_child":
		var sl = (qH || this).ak(CN);
		if (!sl) {
			return (0);
		}
		(qH || this).fJ(aX, sl, 0);
		break;
	  case "item_sibling":
		var sl = (qH || this).ak(CN);
		if (!sl) {
			return (0);
		}
		(qH || this).fJ(aX, sl.parentObject, sl);
		break;
	  case "item_sibling_next":
		var sl = (qH || this).ak(CN);
		if (!sl) {
			return (0);
		}
		if ((sl.tr) && (sl.tr.nextSibling) && (sl.tr.nextSibling.mX)) {
			(qH || this).fJ(aX, sl.parentObject, sl.tr.nextSibling.mX);
		} else {
			(qH || this).fJ(aX, sl.parentObject);
		}
		break;
	  case "left":
		if (aX.parentObject.parentObject) {
			this.fJ(aX, aX.parentObject.parentObject, aX.parentObject);
		}
		break;
	  case "up":
		var z = this.pR(aX);
		if ((z == -1) || (!z.parentObject)) {
			return;
		}
		this.fJ(aX, z.parentObject, z);
		break;
	  case "up_strict":
		var z = this.SA(aX);
		if (z != 0) {
			this.fJ(aX, aX.parentObject, aX.parentObject.childNodes[z - 1]);
		}
		break;
	  case "down_strict":
		var z = this.SA(aX);
		var count = aX.parentObject.aE - 2;
		if (z == count) {
			this.fJ(aX, aX.parentObject);
		} else {
			if (z < count) {
				this.fJ(aX, aX.parentObject, aX.parentObject.childNodes[z + 2]);
			}
		}
		break;
	  case "down":
		var z = this.ob(this.qK(aX));
		if ((z == -1) || (!z.parentObject)) {
			return;
		}
		if (z.parentObject == aX.parentObject) {
			var z = this.ob(z);
		}
		if (z == -1) {
			this.fJ(aX, aX.parentObject);
		} else {
			if ((z == -1) || (!z.parentObject)) {
				return;
			}
			this.fJ(aX, z.parentObject, z);
		}
		break;
	}
};
C.prototype.setDragBehavior = function (mode, select) {
	this.alG = (!K(select));
	switch (mode) {
	  case "child":
		this.mj = 0;
		break;
	  case "sibling":
		this.mj = 1;
		break;
	  case "complex":
		this.mj = 2;
		break;
	}
};
C.prototype.pA = function (id, src) {
	src = src || this.fs;
	var sn = (new Date()).valueOf();
	this.xA = id;
	if (this.Wa == "function") {
		if (src) {
			src(this.xZ(id));
		}
	} else {
		if (this.Wa == "name") {
			this.loadXML(src + this.xZ(id));
		} else {
			if (this.Wa == "xmlname") {
				this.loadXML(src + this.xZ(id) + ".xml?uid=" + sn);
			} else {
				this.loadXML(src + jv(src) + "uid=" + sn + "&id=" + this.xZ(id));
			}
		}
	}
};
C.prototype.enableMultiselection = function (mode, strict) {
	this.Wj = K(mode);
	this.aim = K(strict);
};
C.prototype.wb = function () {
	var ahv = new Array();
	for (var i = 0; i < this._selected.length; i++) {
		for (var j = 0; j < this._selected.length; j++) {
			if ((i != j) && (this.wj(this._selected[j], this._selected[i]))) {
				ahv[ahv.length] = this._selected[j];
			}
		}
	}
	for (var i = 0; i < ahv.length; i++) {
		this.rH(ahv[i]);
	}
};
C.prototype.wj = function (abY, item2) {
	if (item2 == abY) {
		return 1;
	}
	if (abY.parentObject) {
		return this.wj(abY.parentObject, item2);
	} else {
		return 0;
	}
};
C.prototype.enableDistributedParsing = function (mode, count, amY) {
	this.Lz = K(mode);
	this.hv = new Array();
	this.afa = count || 10;
	this.afv = amY || 250;
};
C.prototype.AM = function () {
	return (!((!this.hv) || (!this.hv.length)));
};
C.prototype.xF = function (itemId) {
	var z = this.ak(itemId, true, true);
	if (!z) {
		return 0;
	}
	if (this.hv) {
		for (var i = 0; i < this.hv.length; i++) {
			if (this.hv[i][2] == itemId) {
				return -1;
			}
		}
	}
	return 1;
};
C.prototype.LH = function (node, start, parentId, gR, ako) {
	if (!this.hv) {
		this.hv = new Array();
	}
	this.hv[this.hv.length] = [node, start, parentId, gR, ako];
};
C.prototype.NX = function (FC) {
	var self = this;
	if ((!this.hv) || (!this.hv.length)) {
		self.ek = 0;
		return;
	}
	var z = this.hv[0];
	this.jy = new Array();
	this.Aq(z[0], z[2], z[3], z[1]);
	var aot = this.ak(z[2]);
	this.jm(this, aot, z[4], this.dD(aot));
	var wG = this.sK.split(this.jB);
	for (var n = 0; n < wG.length; n++) {
		if (wG[n]) {
			this.mA(wG[n], 1);
		}
	}
	this.hv = (new Array()).concat(this.hv.slice(1));
	if ((!this.hv.length)) {
		window.setTimeout(function () {
			if (self.onXLE) {
				self.onXLE(self, FC);
			}
			self.callEvent("onXLE", [self, FC]);
		}, 1);
		self.ku = 0;
	}
};
C.prototype.lL = function (mode, adZ) {
	this.adO = K(mode);
	this.Lo = adZ || 50;
};
C.prototype.Og = function (node, pos, gR, Rq) {
	var z = document.createElement("DIV");
	z.innerHTML = "Previous " + this.Lo + " items";
	z.className = "dhx_next_button";
	var self = this;
	z.onclick = function () {
		self.Ur(this);
	};
	z.gH = [node, pos, gR, Rq];
	var w = node.childNodes[0];
	var w2 = w.span.parentNode.parentNode.parentNode.parentNode.parentNode;
	w2.insertBefore(z, w2.firstChild);
};
C.prototype.Od = function (node, pos, gR, Rq) {
	var z = document.createElement("DIV");
	z.innerHTML = "Next " + this.Lo + " items";
	z.className = "dhx_next_button";
	var self = this;
	z.onclick = function () {
		self.TW(this);
	};
	z.gH = [node, pos, gR, Rq];
	var w = node.childNodes[node.aE - 1];
	w.span.parentNode.parentNode.parentNode.parentNode.parentNode.appendChild(z);
};
C.prototype.TW = function (node) {
	tree.fa(node.gH[0].id);
	node.parentNode.removeChild(node);
	var f = this.dD(node.gH[0]);
	this.hf(this, node.gH[3], node.gH[0].id, node.gH[2], null, node.gH[1]);
	this.jm(this, node.gH[0], 0);
	if (f > -1) {
		this.nk(node.gH[0]);
	}
	node.gH = null;
};
C.prototype.Ur = function (node) {
	tree.fa(node.gH[0].id);
	node.parentNode.removeChild(node);
	var f = this.dD(node.gH[0]);
	var xz = node.gH[1] - this.Lo;
	if (xz < 0) {
		xz = 0;
	}
	this.hf(this, node.gH[3], node.gH[0].id, node.gH[2], null, xz);
	this.jm(this, node.gH[0], 0);
	if (f > -1) {
		this.nk(node.gH[0]);
	}
	node.gH = null;
};
C.prototype.enableTextSigns = function (mode) {
	this.Lu = K(mode);
};
C.prototype.vq = function (mode) {
	this.ir = K(mode);
	this.dF.hN = this.ir;
};
C.prototype.jJ = C.prototype.vq;
C.prototype.ox = function (itemId, mode) {
	if (typeof (itemId) != "object") {
		var aX = this.ak(itemId, 0, 1);
	} else {
		var aX = itemId;
	}
	if (!aX) {
		return;
	}
	aX.vO = K(mode) ? (((aX.cY || 0) % 3) + 3) : ((aX.cY > 2) ? (aX.cY - 3) : aX.cY);
	this.bL(aX);
	if (aX.vO < 3) {
		aX.vO = false;
	}
};
C.prototype.adY = function (itemId, source) {
	this.ve = 1;
	this.rq(itemId, source);
};
C.prototype.rq = function (itemId, source) {
	var aX = this.ak(itemId);
	for (var i = 0; i < aX.aE; i++) {
		aX.childNodes[i].acD = true;
	}
	this.hL = true;
	if (source && source.exists) {
		this.Aq(source, itemId);
	} else {
		this.pA(itemId, source);
	}
};
C.prototype.WY = function (Ph, source) {
	var z = Ph.toString().split(this.jB);
	this.hL = new Array();
	for (var i = 0; i < z.length; i++) {
		this.hL[z[i]] = true;
	}
	this.loadXML((source || this.fs) + jv(source || this.fs) + "ids=" + this.xZ(Ph));
};
C.prototype.aak = function (itemId, name, im0, im1, im2, agV) {
	var aX = this.ak(itemId);
	aX.userData = new Fn();
	if (name) {
		aX.label = name;
	}
	aX.images = new Array(im0 || this.gZ[0], im1 || this.gZ[1], im2 || this.gZ[2]);
	this.setItemText(itemId, name);
	if (agV) {
		this.bL(aX, true);
	}
	this.cE(aX);
	aX.acD = false;
	return aX;
};
C.prototype.tE = function (aQ) {
	this.attachEvent("onDrop", aQ);
};
C.prototype.eF = function (aQ) {
	this.attachEvent("onXLS", aQ);
};
C.prototype.dT = function (aQ) {
	this.attachEvent("onXLE", aQ);
};
C.prototype.rx = function (mode) {
	this.Wa = mode;
};
C.prototype.enableSmartCheckboxes = function (mode) {
	this.xL = K(mode);
};
C.prototype.amy = function () {
	return (this.ku == 1);
};
C.prototype.Cx = function (itemId, value) {
	if (typeof (itemId) == "string") {
		var node = this.ak(itemId);
	} else {
		var node = itemId;
	}
	var z = node.span.parentNode.parentNode;
	for (var i = 0; i < z.childNodes.length; i++) {
		if (i != 0) {
			z.childNodes[i].style.height = 18 + parseInt(value) + "px";
		} else {
			var w = z.childNodes[i].firstChild;
			if (z.childNodes[i].firstChild.tagName != "DIV") {
				w = document.createElement("DIV");
				z.childNodes[i].insertBefore(w, z.childNodes[i].firstChild);
			}
			w.style.height = parseInt(value) + "px";
			if ((node.parentObject.id != this.fO || node.parentObject.childNodes[0] != node) && this.Fc) {
				w.style.backgroundImage = "url(" + this.mF + this.wf[5] + ")";
			}
			w.innerHTML = "&nbsp;";
			w.style.overflow = "hidden";
			if (parseInt(value) == 0) {
				z.childNodes[i].removeChild(w);
			}
		}
		z.childNodes[i].vAlign = "bottom";
	}
};
C.prototype.yZ = function (Vc, SQ, itemId) {
	if (itemId) {
		if ((itemId) && (itemId.span)) {
			var aX = itemId;
		} else {
			var aX = this.ak(itemId);
		}
		if (!aX) {
			return (0);
		}
		var img = aX.span.parentNode.previousSibling.childNodes[0];
		if (Vc) {
			img.style.width = Vc;
			if (window._KHTMLrv) {
				img.parentNode.style.width = Vc;
			}
		}
		if (SQ) {
			img.style.height = SQ;
			if (window._KHTMLrv) {
				img.parentNode.style.height = SQ;
			}
		}
	} else {
		this.ST = Vc;
		this.SR = SQ;
	}
};
C.prototype.getItemImage = function (itemId, agI, agb) {
	var node = this.ak(itemId);
	if (!node) {
		return "";
	}
	var img = node.images[agI || 0];
	if (agb) {
		img = this.iconURL + img;
	}
	return img;
};
C.prototype.enableRadioButtons = function (itemId, mode) {
	if (arguments.length == 1) {
		this.Co = K(itemId);
		this.ps = this.ps || this.Co;
		return;
	}
	var node = this.ak(itemId);
	if (!node) {
		return "";
	}
	mode = K(mode);
	if ((mode) && (!node.nN)) {
		node.nN = true;
		for (var i = 0; i < node.aE; i++) {
			this.bL(node.childNodes[i], node.childNodes[i].cY);
		}
	}
	if ((!mode) && (node.nN)) {
		node.nN = false;
		for (var i = 0; i < node.aE; i++) {
			this.bL(node.childNodes[i], node.childNodes[i].cY);
		}
	}
};
C.prototype.enableSingleRadioMode = function (mode) {
	this.aih = K(mode);
};
C.prototype.acK = function (mode) {
	this.agX = !K(mode);
};
C.prototype.Dd = function (mode) {
	this.agX = !K(mode);
};
C.prototype.enableMultiLineItems = function (width) {
	if (width === true) {
		this.Li = "100%";
	} else {
		this.Li = width;
	}
};
C.prototype.enableAutoTooltips = function (mode) {
	this.anL = K(mode);
};
C.prototype.pL = function (itemId) {
	if (itemId) {
		this.rH(this.ak(itemId));
	} else {
		this.Fo();
	}
};
C.prototype.wM = function (itemId, state) {
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	var z = AT.span.parentNode.previousSibling.previousSibling.previousSibling;
	if (!K(state)) {
		this.nk(AT);
		AT.ro = false;
		AT.abd = true;
	} else {
		AT.ro = true;
		AT.abd = false;
	}
	this.cE(AT);
};
C.prototype.nR = function (itemId, state) {
	if (!itemId) {
		for (var a in this.gQ) {
			this.nR(this.gQ[a], state);
		}
	}
	if (typeof (itemId) != "object") {
		itemId = this.ak(itemId, 0, 0);
	}
	if (!itemId) {
		return 0;
	}
	itemId.BC = !K(state);
	var t = itemId.span.parentNode.previousSibling.previousSibling.childNodes[0];
	t.style.display = (!itemId.BC) ? "" : "none";
	if (window._KHTMLrv) {
		t.parentNode.style.display = (!itemId.BC) ? "" : "none";
	}
};
C.prototype.afn = function (separator) {
	this.jB = separator;
};
C.prototype.ahW = function (mode) {
	this.aeh = mode;
};
C.prototype.enableHighlighting = function (mode) {
	this.WG = true;
	this.aht = K(mode);
};
C.prototype.It = function () {
	var that = this.childNodes[3].parentObject;
	var tree = that.treeNod;
	tree.callEvent("onMouseOut", [that.id]);
	if (that.id == tree.NC) {
		tree.NC = null;
	}
	if (!tree.aht) {
		return;
	}
	that.span.className = that.span.className.replace("_lor", "");
};
C.prototype.Jf = function () {
	var that = this.childNodes[3].parentObject;
	var tree = that.treeNod;
	if (tree.NC != that.id) {
		tree.callEvent("onMouseIn", [that.id]);
	}
	tree.NC = that.id;
	if (!tree.aht) {
		return;
	}
	that.span.className = that.span.className.replace("_lor", "");
	that.span.className = that.span.className.replace(/((standart|selected)TreeRow)/, "$1_lor");
};
C.prototype.aey = function (mode) {
	this.Jm = K(mode);
};
C.prototype.Jz = function (itemId) {
	var aX = this.ak(itemId);
	if (!aX) {
		return (0);
	}
	this.QH(aX);
};
C.prototype.Fx = function (itemId) {
	return this.DK(itemId);
};
C.prototype.Qp = function () {
	return this.oi(this.ao);
};
C.prototype.XP = C.prototype.Qp;
C.prototype.oi = function (node) {
	var z = "";
	for (var i = 0; i < node.aE; i++) {
		if ((node.childNodes[i].bZ) || (node.childNodes[i].aE > 0)) {
			if (node.childNodes[i].bZ) {
				var zb = this.uD(node.childNodes[i].bZ, 1);
			} else {
				var zb = this.oi(node.childNodes[i]);
			}
			if (zb) {
				if (z) {
					z += this.jB + zb;
				} else {
					z = zb;
				}
			}
		} else {
			if (!z) {
				z = node.childNodes[i].id;
			} else {
				z += this.jB + node.childNodes[i].id;
			}
		}
	}
	return z;
};
C.prototype.sj = function (node) {
	var z = "";
	for (var i = 0; i < node.aE; i++) {
		if ((node.childNodes[i].bZ) || (node.childNodes[i].aE > 0)) {
			if (!z) {
				z = node.childNodes[i].id;
			} else {
				z += this.jB + node.childNodes[i].id;
			}
			if (node.childNodes[i].bZ) {
				var zb = this.zW(node.childNodes[i].bZ, 1);
			} else {
				var zb = this.sj(node.childNodes[i]);
			}
			if (zb) {
				z += this.jB + zb;
			}
		}
	}
	return z;
};
C.prototype.IK = function () {
	return this.sj(this.ao);
};
C.prototype.Rv = C.prototype.IK;
C.prototype.mv = function () {
	return this.nB("", "", 1);
};
C.prototype.Qq = function (itemId) {
	if (itemId) {
		itemId = this.ak(itemId);
	}
	return this.nB(itemId, "", 0);
};
C.prototype.Fh = function () {
	return this.nB("", "", 2);
};
C.prototype.FX = function () {
	var AT = this.nB("", "", 1);
	if (AT != "") {
		AT += this.jB;
	}
	return AT + this.nB("", "", 2);
};
C.prototype.nB = function (ao, list, mode) {
	if (!ao) {
		ao = this.ao;
	}
	if (ao.cY == mode) {
		if (!ao.BC) {
			if (list) {
				list += this.jB + ao.id;
			} else {
				list = ao.id;
			}
		}
	}
	var j = ao.aE;
	for (var i = 0; i < j; i++) {
		list = this.nB(ao.childNodes[i], list, mode);
	}
	if (ao.bZ) {
		list = this.LU(ao.bZ, list, mode);
	}
	if (list) {
		return list;
	} else {
		return "";
	}
};
C.prototype.setItemStyle = function (itemId, Kv, resetCss) {
	var resetCss = resetCss || false;
	var AT = this.ak(itemId);
	if (!AT) {
		return 0;
	}
	if (!AT.span.style.cssText) {
		AT.span.setAttribute("style", AT.span.getAttribute("style") + ";" + Kv);
	} else {
		AT.span.style.cssText = resetCss ? Kv : AT.span.style.cssText + ";" + Kv;
	}
};
C.prototype.enableImageDrag = function (mode) {
	this.Xy = K(mode);
};
C.prototype.MJ = function (aQ) {
	this.attachEvent("onDragIn", aQ);
};
C.prototype.enableDragAndDropScrolling = function (mode) {
	this.PZ = K(mode);
};
C.prototype.setSkin = function (name) {
	var YV = this.parentObject.className.replace(/dhxtree_[^ ]*/gi, "");
	this.parentObject.className = YV + " dhxtree_" + name;
};
(function () {
	dhtmlx.extend_api("C", {ahY:function (obj) {
		return [obj.parent, (obj.width || "100%"), (obj.height || "100%"), (obj.root_id || 0)];
	}, 
	auto_save_selection:"enableAutoSavingSelected", 
	auto_tooltip:"enableAutoTooltips", 
	checkbox:"enableCheckBoxes", 
	checkbox_3_state:"enableThreeStateCheckboxes", 
	checkbox_smart:"enableSmartCheckboxes", 
	context_menu:"enableContextMenu", 
	distributed_parsing:"enableDistributedParsing", 
	drag:"enableDragAndDrop", 
	drag_copy:"enableMercyDrag", 
	drag_image:"enableImageDrag", 
	drag_scroll:"enableDragAndDropScrolling", 
	editor:"enableItemEditor", 
	hover:"enableHighlighting", 
	images:"enableTreeImages", 
	image_fix:"enableIEImageFix", 
	image_path:"setImagePath", 
	lines:"enableTreeLines", 
	loading_item:"enableLoadingItem", 
	multiline:"enableMultiLineItems", 
	multiselect:"enableMultiselection", 
	navigation:"enableKeyboardNavigation", 
	radio:"enableRadioButtons", 
	radio_single:"enableSingleRadioMode", 
	rtl:"enableRTL", 
	search:"enableKeySearch", 
	smart_parsing:"enableSmartXMLParsing", 
	smart_rendering:"enableSmartRendering", 
	text_icons:"enableTextSigns", 
	xml:"loadXML", 
	skin:"setSkin"}, {});
})();

dhtmlXTreeObject.prototype.enableContextMenu=function(menu){

if(!menu&&!menu.showContextMenu) throw new Error("错误的菜单对象!");

var _tree=this;
//绑定菜单事件处理函数
menu.attachEvent("onBeforeContextMenu",function(){
   if(_tree.rclk_id){
    return true;
   }else{
    return false;
   }
});

menu.attachEvent("onClick",function(){
   _tree.rclk_id=null;  
});

//绑定树控件相关时间处理函数
_tree.attachEvent("onClick",function(sId){
   if(_tree.lastFocusItem){
    if(_isIE)
     _tree.lastFocusItem.className="standartTreeRow";
    else 
       _tree.lastFocusItem.setAttribute("class","standartTreeRow");
   }  
   _tree.lastFocusItem=_tree._idpull[sId].span;
});

_tree.attachEvent("onRightClick",function(id,e){
   var srcEl=e.target||e.srcElement;

   if(srcEl.tagName!="SPAN") return;  
    if(_tree.lastFocusItem){
     if(_isIE)
      _tree.lastFocusItem.className="standartTreeRow";
     else 
      _tree.lastFocusItem.setAttribute("class","standartTreeRow");
   }  
   _tree.lastFocusItem=srcEl;
  
   if(_isIE)
    srcEl.className="selectedTreeRow";
   else
    srcEl.setAttribute("class","selectedTreeRow"); 
  
   _tree.rclk_id=id; 
});
}


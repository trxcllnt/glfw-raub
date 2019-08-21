'use strict';

const glfw   = require('../core');
const Window = require('./window');


const ESC_KEY = 27;
const F_KEY = 70;


class Document extends Window {
	
	static setImage(Image) {
		this.Image = Image;
		global.HTMLImageElement = Image;
	}
	
	static setWebgl(webgl) {
		this.webgl = webgl;
		this.isWebglInited = false;
	}
	
	static exit() {
		process.exit(0);
	}
	
	constructor(opts = {}) {
		
		super(opts);
		
		if (Document.webgl && ! Document.isWebglInited) {
			if (typeof Document.webgl.init === 'function') {
				Document.webgl.init();
			}
			Document.isWebglInited = true;
		}
		
		if ( ! opts.ignoreQuit ) {
			
			const isUnix = process.platform !== 'win32';
			if ( isUnix && process.listeners('SIGINT').indexOf(Document.exit) < 0 ) {
				process.on('SIGINT', Document.exit);
			}
			
			this.on('quit', () => process.exit(0));
			
			if ( opts.autoEsc ) {
				this.on('keydown', e => e.keyCode === ESC_KEY && process.exit(0));
			}
			
		}
		
		if (opts.autoFullscreen) {
			
			this.on('keydown', e => {
				if (e.keyCode === F_KEY && e.ctrlKey && e.shiftKey) {
					this.mode = 'windowed';
				} else if (e.keyCode === F_KEY && e.ctrlKey && e.altKey) {
					this.mode = 'fullscreen';
				} else if (e.keyCode === F_KEY && e.ctrlKey) {
					this.mode = 'borderless';
				}
			});
			
		}
		
		this.swapBuffers();
		
		const sizeWin = this.size;
		const sizeFB  = this.framebufferSize;
		
		this._ratio = sizeFB.width / sizeWin.width;
		this._width = this._width * this._ratio;
		this._height = this._height * this._ratio;
		setInterval(() => glfw.pollEvents(), 0).unref();
	}
		
	get onkeydown() { return this.listeners('keydown'); }
	set onkeydown(cb) { this.on('keydown', cb); }
	
	get onkeyup() { return this.listeners('keyup'); }
	set onkeyup(cb) { this.on('keyup', cb); }
	
	get onmousedown() { return this.listeners('mousedown'); }
	set onmousedown(cb) { this.on('mousedown', cb); }
	
	get onmouseup() { return this.listeners('mouseup'); }
	set onmouseup(cb) { this.on('mouseup', cb); }
	
	get onwheel() { return this.listeners('wheel'); }
	set onwheel(cb) { this.on('wheel', cb); }
	
	get onmousewheel() { return this.listeners('mousewheel'); }
	set onmousewheel(cb) { this.on('mousewheel', cb); }
	
	get onresize() { return this.listeners('resize'); }
	set onresize(cb) { this.on('resize', cb); }
	
	
	get style() {
		const that = this;
		return {
			get width() { return that.width; },
			set width(v) { that.width = parseInt(v); },
			get height() { return that.height; },
			set height(v) { that.height = parseInt(v); },
		};
	}
	
	
	get context() { return Document.webgl; }
	
	getContext(kind) {
		return kind === '2d' ? new Document.Image() : Document.webgl;
	}
	
	
	getElementById() { return this; }
	
	getElementsByTagName() { return this; }
	
	appendChild() {}
	
	
	createElementNS(_0, name) { return this.createElement(name); }
	
	createElement(name) {
		
		name = name.toLowerCase();
		
		if (name.indexOf('canvas') >= 0) {
			
			if ( ! this._isCanvasRequested ) {
				this._isCanvasRequested = true;
				return this;
			}
			
			const that = this;
			
			return {
				_ctx   : null,
				width  : this.width,
				height : this.height,
				
				getContext(kind) {
					this._ctx = that.getContext(kind);
					return this._ctx;
				},
				
				get data() {
					return this._ctx && this._ctx.data;
				},
				
				onkeydown    : () => {},
				onkeyup      : () => {},
				onmousedown  : () => {},
				onmouseup    : () => {},
				onwheel      : () => {},
				onmousewheel : () => {},
				onresize     : () => {},
				
				dispatchEvent       : () => {},
				addEventListener    : () => {},
				removeEventListener : () => {},
				getBoundingClientRect() {
					return {
						   x: 0,   y: 0, width: this.width, height: this.height,
						left: 0, top: 0, right: this.width, bottom: this.height,
					};
				}
			};
			
		} else if (name.indexOf('img') >= 0) {
			
			return new Document.Image();
			
		}
		
		return null;
		
	}
	
	
	dispatchEvent(event) { this.emit(event.type, event); }
	
	addEventListener(name, callback) { this.on(name, callback); }
	
	removeEventListener(name, callback) { this.removeListener(name, callback); }
	
}


global.HTMLCanvasElement = Document;


Document.setImage(class FakeImage {
	get src() {
		console.error('Document.Image class not set.');
		return '';
	}
	set src(v) {
		console.error('Document.Image class not set.');
		v = null;
	}
	get complete() { return false; }
	on() {}
	onload() {}
	onerror() {}
});

Document.setWebgl(null);


module.exports = Document;

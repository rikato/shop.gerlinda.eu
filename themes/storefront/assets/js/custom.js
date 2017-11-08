jQuery( window ).load( function() {
	jQuery(function() {
		function randomColorForProduct () {
			function shuffle(array) {
			  var currentIndex = array.length, temporaryValue, randomIndex;
			  // While there remain elements to shuffle...
			  while (0 !== currentIndex) {
			    // Pick a remaining element...
			    randomIndex = Math.floor(Math.random() * currentIndex);
			    currentIndex -= 1;
			    // And swap it with the current element.
			    temporaryValue = array[currentIndex];
			    array[currentIndex] = array[randomIndex];
			    array[randomIndex] = temporaryValue;
			  }
			  return array;
			}
			if(jQuery(".products").length){
				
				var i = 0;
				jQuery("ul.products>li img").each(function(index) {
					var colors = ["#AADACF", "#E8A793", "#DBD6D2"];
					if(index < 3){
						jQuery(this).css("background-color", colors[i]);		
					}else{
						colors = shuffle(colors);
						jQuery(this).css("background-color", colors[i]);	
					}
					i = (i + 1) % colors.length;
				});
			}
		}
		// var colors = ["#E8A793", "#AADACF"];
		var colors = ["#80c3e4", "#b3dff5"];

		function zebraColoringForProducts() {
			if(jQuery(".products").length){
				jQuery("ul.products>li img").each(function(index) {
					jQuery("<div class='product-bg'></div>").insertAfter(this);
					//var colors = ["#E8A793", "#AADACF"];
					// if(index % 2){
					// 	jQuery(this).next().addClass("background-color", colors[0]);
					// }else{
					// 	jQuery(this).next().css("background-color", colors[1]);
					// }
					var colors = ["blue", "red"];
					if(index % 2){
						jQuery(this).next().addClass(colors[0]);
					}else{
						jQuery(this).next().addClass(colors[1]);
					}
				});
			}
		}
		jQuery(".site-info").empty().text("");
		//randomColorForProduct();
		zebraColoringForProducts();
		// setTimeout(function(){
		// 	jQuery("ul.products .product-bg").each(function (index) {
		// 		var self = this
		// 		setTimeout(function () {
  //           		jQuery(self).css({
		// 			  '-webkit-transform' : 'scaleX(250)',
		// 			  '-moz-transform'    : 'scaleX(250)',
		// 			  '-ms-transform'     : 'scaleX(250)',
		// 			  '-o-transform'      : 'scaleX(250)',
		// 			  'transform'         : 'scaleX(250)'
		// 			});
  //     			}, index*200);
		// 	});
		// }, 600);

		//para products
		//jQuery("ul.products").attr("data-uk-grid-parallax", "{translate:200}");
		var productCount = jQuery(".cart-contents span.count").text();
		var intProductCount = parseInt(productCount);
		jQuery(".site-header-cart a.cart-contents").append("<p class='product-amount'>"+intProductCount+ "</p>");
		if (intProductCount < 1) {
			jQuery("#site-header-cart").css("display", "none");
		}
		var productBgColor;
		var open = false;
		jQuery("body").append("<div class='product-popup'><div class='container'><span class='product-popup-close'></span><div class='desc-holder'><h2 class='product-popup-title'></h2><p class='product-popup-desc'></p><span class='product-popup-price'></span><input tpye='number' class='product-popup-amount input-text qty text' step='1' min='1' value='1' title='aantal' size='4' pattern='[0-9]*' inputmode='numeric'><a rel='nofollow' class='product-popup-addtocart button product_type_simple add_to_cart_button ajax_add_to_cart' data-product_sku>in winkelmand</a></div><img class='product-popup-image'><div class='product-popup-background'></div></div></div>")
			
			var productNamePopup = jQuery(this).find("h2.product-popup-title").text();
			var productImagePopup = jQuery(this).find("img.product-popup-image").attr("src");
			
		// jQuery(".product-popup-addtocart").on("click", function() {
		// 	jQuery(this).text("even geduld");

		// });

		var currentUrlProduct = window.location.hash.substr(1);
		if(currentUrlProduct.indexOf("product") >= 0) {
			console.log(currentUrlProduct);
			var number = currentUrlProduct.replace(/[^0-9]/g, '');
			console.log(jQuery("li.post-"+number+" a"));
			setTimeout(function() {
        		jQuery("li.post-"+number+" a").trigger("click");
   		 	},10);
			
		}

		jQuery("span.product-popup-close").on("click", function () {

		var productCount = jQuery(".cart-contents span.count").text();
		var intProductCount = parseInt(productCount);
		jQuery(".site-header-cart a.cart-contents").append("<p class='product-amount'>"+intProductCount+ "</p>");
		if (intProductCount < 1) {
			jQuery("#site-header-cart").css("display", "none");
		}else{
			jQuery("#site-header-cart").css("display", "block");
		}
			if (open == true) {
				history.pushState("", document.title, window.location.pathname+ window.location.search);
				    jQuery("ul.products.popup-open").removeClass("popup-open");
					jQuery("li.product.clicked-product").removeClass("clicked-product");
				//reset coloring after product closed.
			// jQuery(".product-bg").each(function () {
			// 	jQuery(this).remove();
			// });
				// zebraColoringForProducts();
				setTimeout(function(){
					jQuery(".product-popup-background") .css({
					  '-webkit-transform' : 'scaleX(0)',
					  '-moz-transform'    : 'scaleX(0)',
					  '-ms-transform'     : 'scaleX(0)',
					  '-o-transform'      : 'scaleX(0)',
					  'transform'         : 'scaleX(0)'
					});
				}, 800);
				jQuery(".product-popup-image, .desc-holder").removeClass("fadeIn").removeClass("animated");
				jQuery(".product-popup-image, .desc-holder").addClass("fadeOut").addClass("animated");
				setTimeout(function(){
					jQuery(".product-popup-image, .desc-holder").removeClass("fadeOut").removeClass("animated");
					jQuery(".product a.wait-for-anim img.attachment-shop_catalog").addClass("activeAnim");
					jQuery(".product a.wait-for-anim .product-bg").addClass("activeAnim");
					jQuery(".product-popup .container").css("opacity", 0);
					jQuery(".product-popup").removeClass("active");		
					setTimeout(function(){
						jQuery("img.attachment-shop_catalog").removeClass("activeAnim");
						jQuery(".product-bg").removeClass("activeAnim");
						jQuery(".product a.wait-for-anim").removeClass("wait-for-anim");	
						open = false;
					}, 400);
					jQuery(".product-bg").css({
							height: "",
							width: "",
							borderRadius: "",
							top: "",
							left: "",
							zIndex: "",
							'-webkit-transform' : 'scale(1)',
							'-moz-transform'    : 'scale(1)',
							'-ms-transform'     : 'scale(1)',
							'-o-transform'      : 'scale(1)',
							'transform'         : 'scale(1)'
						});
					jQuery(".product-bg.blue").css({
						backgroundColor: colors[1]
					});
					jQuery(".product-bg.red").css({
						backgroundColor: colors[0]
					});
					jQuery(".product-popup-background") .css({
					  '-webkit-transform' : 'scaleX(0)',
					  '-moz-transform'    : 'scaleX(0)',
					  '-ms-transform'     : 'scaleX(0)',
					  '-o-transform'      : 'scaleX(0)',
					  'transform'         : 'scaleX(0)'
					});
					jQuery("body").css("overflow", "");
					setTimeout(function(){
						jQuery(".product-popup-addtocart").removeClass("added");
						jQuery("#main ul.products li.product.not-clicked-product:not(clicked-product)").removeClass("remove-tran");
					}, 400);	
				}, 1600);
				
			}
		});
		jQuery("li.product").find("p").hide().addClass("short-desc-shopitem");
		
		jQuery("input.product-popup-amount").on("change", function (){
			var productQty = jQuery(this).val();
			jQuery("a.product-popup-addtocart").attr("data-quantity", productQty);
		});
		var pageWidth, pageHeight;

		var basePage = {
		  width: 315,
		  height: 200,
		  scale: 1,
		  scaleX: 1,
		  scaleY: 1
		};
		(function ( jQuery ) { jQuery.fn.extend({ mouseParallax: function(options) { var defaults = { moveFactor: 5, zIndexValue: "-1", targetContainer: 'body' }; var options = jQuery.extend(defaults, options); return this.each(function() { var o = options; var background = jQuery(this); jQuery(o.targetContainer).on('mousemove', function(e){ mouseX = e.pageX; mouseY = e.pageY; windowWidth = jQuery(window).width(); windowHeight = jQuery(window).height(); percentX = ((mouseX/windowWidth)*o.moveFactor) - (o.moveFactor/2); percentY = ((mouseY/windowHeight)*o.moveFactor) - (o.moveFactor/2); leftString = (0-percentX-o.moveFactor)+"%"; rightString = (0-percentX-o.moveFactor)+"%"; topString = (0-percentY-o.moveFactor)+"%"; bottomString = (0-percentY-o.moveFactor)+"%"; background[0].style.left = leftString; background[0].style.right = rightString; background[0].style.top = topString; background[0].style.bottom = bottomString; if(o.zIndexValue) { background[0].style.zIndex = o.zIndexValue; } }); }); } }); } (jQuery) );

		//jQuery('.product-popup-background').mouseParallax({ moveFactor: 1 });
		jQuery('.product-popup-image').mouseParallax({ moveFactor: 3 });
	
		// jQuery("ul.products li.product:nth-child(3n+2)").addClass("add-margin");

		jQuery(document).on("click", "li.product a", function(e) {

			if (open == false) {

				jQuery("li.product:not(.clicked-product)").addClass("not-clicked-product");
				jQuery(this).parent().addClass("clicked-product");
				jQuery("#main ul.products li.product.not-clicked-product:not(clicked-product)").addClass("remove-tran");
				jQuery("ul.products").addClass("popup-open");
				setTimeout(function(){
	 				jQuery(".product-popup-background") .css({
					  '-webkit-transform' : 'scaleX(500)',
					  '-moz-transform'    : 'scaleX(500)',
					  '-ms-transform'     : 'scaleX(500)',
					  '-o-transform'      : 'scaleX(500)',
					  'transform'         : 'scaleX(500)'
					});
					jQuery(".product-popup-image").addClass("fadeIn").addClass("animated");
					setTimeout(function(){
						jQuery(".desc-holder").addClass("fadeIn").addClass("animated");
						open = true;
					}, 800);	
				}, 400);	

			}
			
				// jQuery("#main ul.products li.product.not-clicked-product:not(clicked-product)") .css({
				// 		  '-webkit-transform' : 'none',
				// 		  '-moz-transform'    : 'none',
				// 		  '-ms-transform'     : 'none',
				// 		  '-o-transform'      : 'none',
				// 		  'transform'         : 'none'
				// 		});
			//getting all details needed for the product popup
			var productName = 	   jQuery(this).find("h2.woocommerce-loop-product__title").text();
			var productshortDesc = jQuery(this).find(".short-desc-shopitem").text();
			var productPrice = 	   jQuery(this).find("span.price").text();
			var productColor = 	   jQuery(this).find(".product-bg").css("background-color");
			var productImage = 	   jQuery(this).find("img").attr("src");
			var productId = 	   jQuery(this).next("a.button.product_type_simple.add_to_cart_button.ajax_add_to_cart").attr("data-product_id");
			var newValue = productImage.replace('-300x300', '');
			//logging clicked product details
			console.log("productName: "		,productName);
			console.log("productshortDesc: ", productshortDesc);
			console.log("productPrice: "	, productPrice);
			console.log("productColor: "	, productColor);
			console.log("productImage: "	, productImage);
			console.log("productId: "	    , productId);
			//bg color
			productBgColor = productColor;
			//activating popup
			jQuery(".product-popup").addClass("active");
			jQuery(this).addClass("wait-for-anim");
			//filling product popup with the details
			jQuery("h2.product-popup-title")  .text(productName);
			jQuery("p.product-popup-desc")	  .text(productshortDesc);
			jQuery("span.product-popup-price").text(productPrice);
			jQuery(".product-popup-image")	  .attr("src", newValue);
			//jQuery("a.product-popup-addtocart") .attr("data-product_id", productId);
			jQuery("a.product-popup-addtocart") .attr("href", "/?add-to-cart="+productId);
			jQuery("a.product-popup-addtocart") .attr("data-product_id", productId);
			jQuery("span.product-popup-close") .attr("data-bgColor", productColor);
			jQuery(".product-popup-background") .css("background-color", productColor);

			document.location.hash = "product"+productId;
			//click animation

			var bg = jQuery(this).find(".product-bg");
			// var wH = jQuery( window ).height();
 			// var wW = jQuery( window ).width();

			var $page = bg;

			getPageSize();
			scalePages($page, pageWidth, pageHeight);
	

			function getPageSize() {
				pageHeight = jQuery(window).height();
				pageWidth = jQuery(window).width();
			}

			function scalePages(page, maxWidth, maxHeight) {            
				var scaleX = 1, scaleY = 1;                      
				scaleX = maxWidth / basePage.width;
				scaleY = maxHeight / basePage.height;
				basePage.scaleX = scaleX;
				basePage.scaleY = scaleY;
				basePage.scale = scaleY * scaleX;
				/*
				scaleX = maxWidth / basePage.width;
				scaleY = maxHeight / basePage.height *2;
				basePage.scaleX = scaleX;
				basePage.scaleY = scaleY;
				basePage.scale = (scaleX > scaleY) ? scaleY : scaleX;
				*/
				page.css({
				  '-webkit-transform' : 'scale(' + basePage.scale * 3 + ')',
				  '-moz-transform'    : 'scale(' + basePage.scale * 3 + ')',
				  '-ms-transform'     : 'scale(' + basePage.scale * 3 + ')',
				  '-o-transform'      : 'scale(' + basePage.scale * 3 + ')',
				  'transform'         : 'scale(' + basePage.scale * 3 + ')'
				});
			}

			bg.css({
				backgroundColor: "#F3F3F5",
				zIndex: "999"
			});


			jQuery(".product-popup .container").css("opacity", 1);

			jQuery("body").css("overflow", "hidden");
			// setTimeout(function(){
  	//  		jQuery(".product-popup").css("background-color", productColor);
	  // 			bg.css({
			// 		borderRadius: "0"
			// 	});
			// }, 200);
			//preventing click event
			return false; 
		});	
		
		//scrollmagic
		var wh = window.innerHeight,
		    jQuerycontainer = jQuery(".cotainer"),
		    jQueryul = jQuery(".ul"),
		    jQueryli = jQuery("li.product"),
		    jQueryimg = jQuery("li img");

		var ctrl = new ScrollMagic.Controller;

		var imgH =  450;
		// Create scene
		jQuery("li.product").each(function() {
		    new ScrollMagic.Scene({
		        triggerElement: this,
		        triggerHook: 0.9,
		    })
		    .setClassToggle(this, 'scroll-up')
		  //   .addIndicators({
				// 	name: 'fade scene',
				// 	colorTrigger: 'red',
				// 	colorStart: '#75C695',
				// 	colorEnd: 'pink'
				// })
		    .addTo(ctrl);
		});

	});
});
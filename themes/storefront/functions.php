<?php
/**
 * Storefront engine room
 *
 * @package storefront
 */

/**
 * Assign the Storefront version to a var
 */
$theme              = wp_get_theme( 'storefront' );
$storefront_version = $theme['Version'];

/**
 * Set the content width based on the theme's design and stylesheet.
 */
if ( ! isset( $content_width ) ) {
	$content_width = 980; /* pixels */
}

$storefront = (object) array(
	'version' => $storefront_version,

	/**
	 * Initialize all the things.
	 */
	'main'       => require 'inc/class-storefront.php',
	'customizer' => require 'inc/customizer/class-storefront-customizer.php',
);

require 'inc/storefront-functions.php';
require 'inc/storefront-template-hooks.php';
require 'inc/storefront-template-functions.php';

if ( class_exists( 'Jetpack' ) ) {
	$storefront->jetpack = require 'inc/jetpack/class-storefront-jetpack.php';
}

if ( storefront_is_woocommerce_activated() ) {
	$storefront->woocommerce = require 'inc/woocommerce/class-storefront-woocommerce.php';

	require 'inc/woocommerce/storefront-woocommerce-template-hooks.php';
	require 'inc/woocommerce/storefront-woocommerce-template-functions.php';
}

if ( is_admin() ) {
	$storefront->admin = require 'inc/admin/class-storefront-admin.php';
}

add_action( 'init', 'jk_remove_storefront_cart' );
function jk_remove_storefront_cart() {
	add_action( 'storefront_header', 'storefront_header_cart', 20 );
	remove_action( 'storefront_header', 'storefront_header_cart', 60 );
}

// add_action( 'init', 'jk_remove_storefront_cart' );
// function jk_remove_storefront_cart() {
// 	add_action( 'storefront_header', 'storefront_product_search',    60 );
// 	remove_action( 'storefront_header', 'storefront_product_search', 40 );
// }


wp_enqueue_script( 'custom1', get_stylesheet_directory_uri() . '/assets/js/mouse.parallax.js', array('jquery'), 1.0, true);
wp_enqueue_script( 'custom2', get_stylesheet_directory_uri() . '/assets/js/TweenMax.min.js', array('jquery'), 1.0, true);
wp_enqueue_script( 'custom3', get_stylesheet_directory_uri() . '/assets/js/scrollmagic.js', array('jquery'), 1.0, true);
wp_enqueue_script( 'custom4', get_stylesheet_directory_uri() . '/assets/js/animation.gsap.min.js', array('jquery'), 1.0, true);
wp_enqueue_script( 'custom5', get_stylesheet_directory_uri() . '/assets/js/debug.addIndicators.min.js', array('jquery'), 1.0, true);
wp_enqueue_script( 'custom', get_stylesheet_directory_uri() . '/assets/js/custom.js', array('jquery'), 1.0, true);
// wp_enqueue_script( 'custom2', get_stylesheet_directory_uri() . '/assets/js/uikit.min.js', array('jquery'), 1.0, true);

/**
 * Note: Do not add any custom code here. Please use a custom plugin so that your customizations aren't lost during updates.
 * https://github.com/woocommerce/theme-customisations
 */



// Display 24 products per page. Goes in functions.php
// add_filter( 'loop_shop_per_page', create_function( '$cols', 'return 9;' ), 20 );
<?php
/**
 * Plugin Name: Tutsplus Display Product Short Descriptions in WooCommerce Archive pages
 * Plugin URI: http://code.tutsplus.com/tutorials/woocommerce-adding-the-product-short-description-to-archive-pages--cms-25435
 * Description: Add product short descriptions to the loop in product archive pages (requires WooCommerce to be activated)
 * Version: 1.0
 * Author: Rachel McCollin
 * Author URI: http://rachelmccollin.co.uk
 *
 */

function tutsplus_excerpt_in_product_archives() {
     
    the_excerpt();
     
}

add_action( 'woocommerce_after_shop_loop_item_title', 'tutsplus_excerpt_in_product_archives', 40 );
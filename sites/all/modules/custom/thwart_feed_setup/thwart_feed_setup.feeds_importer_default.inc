<?php
/**
 * @file
 * thwart_feed_setup.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function thwart_feed_setup_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'twitter_mass_scraper';
  $feeds_importer->config = array(
    'name' => 'Twitter mass scraper',
    'description' => 'Twitter scraper system',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'twitter_scrape_item',
        'expire' => '-1',
        'author' => '2',
        'mappings' => array(),
        'update_existing' => '0',
        'input_format' => 'filtered_html',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '900',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['twitter_mass_scraper'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'twitter_scraper_rnc_livepress_rnc2012';
  $feeds_importer->config = array(
    'name' => 'Twitter scraper #rnc #livepress #rnc2012',
    'description' => 'twitter RNC livepress rnc2012',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'twitter_scrape_item',
        'expire' => '-1',
        'author' => '2',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'guid',
            'target' => 'field_unique_guid',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'author_name',
            'target' => 'field_twitter_author',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'filtered_html',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['twitter_scraper_rnc_livepress_rnc2012'] = $feeds_importer;

  return $export;
}

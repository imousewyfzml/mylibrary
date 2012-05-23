


<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# githubog: http://ogp.me/ns/fb/githubog#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>memcached/hash.c at master · memcached/memcached · GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="shortcut icon" href="/favicon.ico" type="image/x-icon" />

    
    

    <meta content="authenticity_token" name="csrf-param" />
<meta content="gSIDRz87OnAvoJkxcv03HnXBCxBlu6r5jsQJobztlhE=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/stylesheets/bundles/github-fb71d2393e1bd50652ea5591ef6eec0431f7550a.css" media="screen" rel="stylesheet" type="text/css" />
    <link href="https://a248.e.akamai.net/assets.github.com/stylesheets/bundles/github2-387859b7528ac68fea78f3087e1109b39a1f23a8.css" media="screen" rel="stylesheet" type="text/css" />
    
    


    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundles/frameworks-e417ea70cc7daa9aad62382cb6b5d0c94acfb8f4.js" type="text/javascript"></script>
    
    <script defer="defer" src="https://a248.e.akamai.net/assets.github.com/javascripts/bundles/github-3109083411e0a9bbb3c7d34b713ad52d826357bf.js" type="text/javascript"></script>
    
    

      <link rel='permalink' href='/memcached/memcached/blob/b19b41d968e064902dd585c68582b687e6ccdfc7/hash.c'>
    <meta property="og:title" content="memcached"/>
    <meta property="og:type" content="githubog:gitrepository"/>
    <meta property="og:url" content="https://github.com/memcached/memcached"/>
    <meta property="og:image" content="https://a248.e.akamai.net/assets.github.com/images/gravatars/gravatar-140.png?1329275985"/>
    <meta property="og:site_name" content="GitHub"/>
    <meta property="og:description" content="memcached development tree. Contribute to memcached development by creating an account on GitHub."/>

    <meta name="description" content="memcached development tree. Contribute to memcached development by creating an account on GitHub." />

  <link href="https://github.com/memcached/memcached/commits/master.atom" rel="alternate" title="Recent Commits to memcached:master" type="application/atom+xml" />

  </head>


  <body class="logged_out page-blob linux vis-public env-production " data-blob-contribs-enabled="yes">
    <div id="wrapper">

    
    
    

      <div id="header" class="true clearfix">
        <div class="container clearfix">
          <a class="site-logo" href="https://github.com/">
            <!--[if IE]>
            <img alt="GitHub" class="github-logo" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7.png?1323882804" />
            <img alt="GitHub" class="github-logo-hover" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7-hover.png?1324325453" />
            <![endif]-->
            <img alt="GitHub" class="github-logo-4x" height="30" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7@4x.png?1337118068" />
            <img alt="GitHub" class="github-logo-4x-hover" height="30" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7@4x-hover.png?1337118068" />
          </a>

                  <!--
      make sure to use fully qualified URLs here since this nav
      is used on error pages on other domains
    -->
    <ul class="top-nav logged_out">
        <li class="pricing"><a href="https://github.com/plans">Signup and Pricing</a></li>
        <li class="explore"><a href="https://github.com/explore">Explore GitHub</a></li>
      <li class="features"><a href="https://github.com/features">Features</a></li>
        <li class="blog"><a href="https://github.com/blog">Blog</a></li>
      <li class="login"><a href="https://github.com/login?return_to=%2Fmemcached%2Fmemcached%2Fblob%2Fmaster%2Fhash.c">Login</a></li>
    </ul>



          
        </div>
      </div>

      

            <div class="site hfeed" itemscope itemtype="http://schema.org/WebPage">
      <div class="container hentry">
        <div class="pagehead repohead instapaper_ignore readability-menu">
        <div class="title-actions-bar">
          



              <ul class="pagehead-actions">



          <li>
            <span class="watch-button"><a href="/login?return_to=%2Fmemcached%2Fmemcached" class="minibutton btn-watch js-toggler-target entice tooltipped leftwards" title="You must be logged in to use this feature" rel="nofollow"><span class="icon"></span> Watch</a><a class="social-count js-social-count" href="/memcached/memcached/watchers">1,576</a></span>
          </li>
          <li>
            <a href="/login?return_to=%2Fmemcached%2Fmemcached" class="minibutton btn-fork js-toggler-target fork-button entice tooltipped leftwards"  title="You must be logged in to use this feature" rel="nofollow"><span class="icon"></span>Fork</a><a href="/memcached/memcached/network" class="social-count">227</a>
          </li>

    </ul>

          <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title">
            <span class="repo-label"><span class="public">public</span></span>
            <span class="mega-icon public-repo"></span>
            <span class="author vcard">
<a href="/memcached" class="url fn" itemprop="url" rel="author">              <span itemprop="title">memcached</span>
              </a></span> /
            <strong><a href="/memcached/memcached" class="js-current-repository">memcached</a></strong>
          </h1>
        </div>

          

  <ul class="tabs">
    <li><a href="/memcached/memcached" class="selected" highlight="repo_sourcerepo_downloadsrepo_commitsrepo_tagsrepo_branches">Code</a></li>
    <li><a href="/memcached/memcached/network" highlight="repo_network">Network</a>
    <li><a href="/memcached/memcached/pulls" highlight="repo_pulls">Pull Requests <span class='counter'>5</span></a></li>



    <li><a href="/memcached/memcached/graphs" highlight="repo_graphsrepo_contributors">Graphs</a></li>

  </ul>
 
<div class="frame frame-center tree-finder" style="display:none"
      data-tree-list-url="/memcached/memcached/tree-list/b19b41d968e064902dd585c68582b687e6ccdfc7"
      data-blob-url-prefix="/memcached/memcached/blob/b19b41d968e064902dd585c68582b687e6ccdfc7"
    >

  <div class="breadcrumb">
    <span class="bold"><a href="/memcached/memcached">memcached</a></span> /
    <input class="tree-finder-input js-navigation-enable" type="text" name="query" autocomplete="off" spellcheck="false">
  </div>

    <div class="octotip">
      <p>
        <a href="/memcached/memcached/dismiss-tree-finder-help" class="dismiss js-dismiss-tree-list-help" title="Hide this notice forever" rel="nofollow">Dismiss</a>
        <span class="bold">Octotip:</span> You've activated the <em>file finder</em>
        by pressing <span class="kbd">t</span> Start typing to filter the
        file list. Use <span class="kbd badmono">↑</span> and
        <span class="kbd badmono">↓</span> to navigate,
        <span class="kbd">enter</span> to view files.
      </p>
    </div>

  <table class="tree-browser" cellpadding="0" cellspacing="0">
    <tr class="js-header"><th>&nbsp;</th><th>name</th></tr>
    <tr class="js-no-results no-results" style="display: none">
      <th colspan="2">No matching files</th>
    </tr>
    <tbody class="js-results-list js-navigation-container">
    </tbody>
  </table>
</div>

<div id="jump-to-line" style="display:none">
  <h2>Jump to Line</h2>
  <form accept-charset="UTF-8">
    <input class="textfield" type="text">
    <div class="full-button">
      <button type="submit" class="classy">
        <span>Go</span>
      </button>
    </div>
  </form>
</div>


<div class="subnav-bar">

  <ul class="actions subnav">
    <li><a href="/memcached/memcached/tags" class="" highlight="repo_tags">Tags <span class="counter">39</span></a></li>
    <li><a href="/memcached/memcached/downloads" class="" highlight="repo_downloads">Downloads <span class="counter">1</span></a></li>
    
  </ul>

  <ul class="scope">
    <li class="switcher">

      <div class="context-menu-container js-menu-container js-context-menu">
        <a href="#"
           class="minibutton bigger switcher js-menu-target js-commitish-button btn-branch repo-tree"
           data-hotkey="w"
           data-master-branch="master"
           data-ref="master">
           <span><span class="icon"></span><i>branch:</i> master</span>
        </a>

        <div class="context-pane commitish-context js-menu-content">
          <a href="javascript:;" class="close js-menu-close"><span class="mini-icon remove-close"></span></a>
          <div class="context-title">Switch Branches/Tags</div>
          <div class="context-body pane-selector commitish-selector js-navigation-container">
            <div class="filterbar">
              <input type="text" id="context-commitish-filter-field" class="js-navigation-enable" placeholder="Filter branches/tags" data-filterable />

              <ul class="tabs">
                <li><a href="#" data-filter="branches" class="selected">Branches</a></li>
                <li><a href="#" data-filter="tags">Tags</a></li>
              </ul>
            </div>

            <div class="js-filter-tab js-filter-branches" data-filterable-for="context-commitish-filter-field">
              <div class="no-results js-not-filterable">Nothing to show</div>
                <div class="commitish-item branch-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/14perf/hash.c" class="js-navigation-open" data-name="14perf" rel="nofollow">14perf</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/engine-pu/hash.c" class="js-navigation-open" data-name="engine-pu" rel="nofollow">engine-pu</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/gh-pages/hash.c" class="js-navigation-open" data-name="gh-pages" rel="nofollow">gh-pages</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/master/hash.c" class="js-navigation-open" data-name="master" rel="nofollow">master</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/stable/hash.c" class="js-navigation-open" data-name="stable" rel="nofollow">stable</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/stable-1.3/hash.c" class="js-navigation-open" data-name="stable-1.3" rel="nofollow">stable-1.3</a>
                  </h4>
                </div>
            </div>

            <div class="js-filter-tab js-filter-tags" style="display:none" data-filterable-for="context-commitish-filter-field">
              <div class="no-results js-not-filterable">Nothing to show</div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.6.0-beta1/hash.c" class="js-navigation-open" data-name="1.6.0-beta1" rel="nofollow">1.6.0-beta1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4-rc1/hash.c" class="js-navigation-open" data-name="1.4-rc1" rel="nofollow">1.4-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.13/hash.c" class="js-navigation-open" data-name="1.4.13" rel="nofollow">1.4.13</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.12/hash.c" class="js-navigation-open" data-name="1.4.12" rel="nofollow">1.4.12</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.11-rc1/hash.c" class="js-navigation-open" data-name="1.4.11-rc1" rel="nofollow">1.4.11-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.11-beta1/hash.c" class="js-navigation-open" data-name="1.4.11-beta1" rel="nofollow">1.4.11-beta1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.11/hash.c" class="js-navigation-open" data-name="1.4.11" rel="nofollow">1.4.11</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.10/hash.c" class="js-navigation-open" data-name="1.4.10" rel="nofollow">1.4.10</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.9-beta1/hash.c" class="js-navigation-open" data-name="1.4.9-beta1" rel="nofollow">1.4.9-beta1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.9/hash.c" class="js-navigation-open" data-name="1.4.9" rel="nofollow">1.4.9</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.8-rc1/hash.c" class="js-navigation-open" data-name="1.4.8-rc1" rel="nofollow">1.4.8-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.8/hash.c" class="js-navigation-open" data-name="1.4.8" rel="nofollow">1.4.8</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.7-rc1/hash.c" class="js-navigation-open" data-name="1.4.7-rc1" rel="nofollow">1.4.7-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.7/hash.c" class="js-navigation-open" data-name="1.4.7" rel="nofollow">1.4.7</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.6-rc1/hash.c" class="js-navigation-open" data-name="1.4.6-rc1" rel="nofollow">1.4.6-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.6/hash.c" class="js-navigation-open" data-name="1.4.6" rel="nofollow">1.4.6</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.5/hash.c" class="js-navigation-open" data-name="1.4.5" rel="nofollow">1.4.5</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.4/hash.c" class="js-navigation-open" data-name="1.4.4" rel="nofollow">1.4.4</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.3-rc2/hash.c" class="js-navigation-open" data-name="1.4.3-rc2" rel="nofollow">1.4.3-rc2</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.3-rc1/hash.c" class="js-navigation-open" data-name="1.4.3-rc1" rel="nofollow">1.4.3-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.3/hash.c" class="js-navigation-open" data-name="1.4.3" rel="nofollow">1.4.3</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.2-rc1/hash.c" class="js-navigation-open" data-name="1.4.2-rc1" rel="nofollow">1.4.2-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.2/hash.c" class="js-navigation-open" data-name="1.4.2" rel="nofollow">1.4.2</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.1-rc1/hash.c" class="js-navigation-open" data-name="1.4.1-rc1" rel="nofollow">1.4.1-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.1/hash.c" class="js-navigation-open" data-name="1.4.1" rel="nofollow">1.4.1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.0-rc1/hash.c" class="js-navigation-open" data-name="1.4.0-rc1" rel="nofollow">1.4.0-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.4.0/hash.c" class="js-navigation-open" data-name="1.4.0" rel="nofollow">1.4.0</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.3.3/hash.c" class="js-navigation-open" data-name="1.3.3" rel="nofollow">1.3.3</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.3.2/hash.c" class="js-navigation-open" data-name="1.3.2" rel="nofollow">1.3.2</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.8/hash.c" class="js-navigation-open" data-name="1.2.8" rel="nofollow">1.2.8</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.7-rc1/hash.c" class="js-navigation-open" data-name="1.2.7-rc1" rel="nofollow">1.2.7-rc1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.7/hash.c" class="js-navigation-open" data-name="1.2.7" rel="nofollow">1.2.7</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.6/hash.c" class="js-navigation-open" data-name="1.2.6" rel="nofollow">1.2.6</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.5/hash.c" class="js-navigation-open" data-name="1.2.5" rel="nofollow">1.2.5</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.4/hash.c" class="js-navigation-open" data-name="1.2.4" rel="nofollow">1.2.4</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.3/hash.c" class="js-navigation-open" data-name="1.2.3" rel="nofollow">1.2.3</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.2/hash.c" class="js-navigation-open" data-name="1.2.2" rel="nofollow">1.2.2</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.1/hash.c" class="js-navigation-open" data-name="1.2.1" rel="nofollow">1.2.1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item js-navigation-item js-navigation-target">
                  <h4>
                      <a href="/memcached/memcached/blob/1.2.0/hash.c" class="js-navigation-open" data-name="1.2.0" rel="nofollow">1.2.0</a>
                  </h4>
                </div>
            </div>
          </div>
        </div><!-- /.commitish-context-context -->
      </div>

    </li>
  </ul>

  <ul class="subnav with-scope">

    <li><a href="/memcached/memcached" class="selected" highlight="repo_source">Files</a></li>
    <li><a href="/memcached/memcached/commits/master" highlight="repo_commits">Commits</a></li>
    <li><a href="/memcached/memcached/branches" class="" highlight="repo_branches" rel="nofollow">Branches <span class="counter">6</span></a></li>
  </ul>

</div>

  
  
  


          

        </div><!-- /.repohead -->

        





<!-- block_view_fragment_key: views8/v8/blob:v21:9c4a00ddc27f72f88727a7a5b519f497 -->
  <div id="slider">

    <div class="breadcrumb" data-path="hash.c/">
      <b itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/memcached/memcached/tree/b19b41d968e064902dd585c68582b687e6ccdfc7" class="js-rewrite-sha" itemprop="url"><span itemprop="title">memcached</span></a></b> / <strong class="final-path">hash.c</strong> <span class="js-clippy mini-icon clippy " data-clipboard-text="hash.c" data-copied-hint="copied!" data-copy-hint="copy to clipboard"></span>
    </div>


      <div class="commit file-history-tease" data-path="hash.c/">
        <img class="main-avatar" height="24" src="https://secure.gravatar.com/avatar/d5c71beba93e296cf862be8308424429?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-140.png" width="24" />
        <span class="author">Trond Norbye</span>
        <time class="js-relative-date" datetime="2009-03-02T01:15:34-08:00" title="2009-03-02 01:15:34">March 02, 2009</time>
        <div class="commit-title">
            <a href="/memcached/memcached/commit/1a070652ba97045c73b5e0f5237d35ea017bb04b" class="message">Refactor: moved the hash function from assoc.c to hash.c</a>
        </div>

        <div class="participation">
          <p class="quickstat"><a href="#blob_contributors_box" rel="facebox"><strong>0</strong> contributors</a></p>
          
        </div>
        <div id="blob_contributors_box" style="display:none">
          <h2>Users on GitHub who have contributed to this file</h2>
          <ul class="facebox-user-list">
          </ul>
        </div>
      </div>

    <div class="frames">
      <div class="frame frame-center" data-path="hash.c/" data-permalink-url="/memcached/memcached/blob/b19b41d968e064902dd585c68582b687e6ccdfc7/hash.c" data-title="memcached/hash.c at master · memcached/memcached · GitHub" data-type="blob">

        <div id="files" class="bubble">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><b class="mini-icon text-file"></b></span>
                <span class="mode" title="File Mode">100644</span>
                  <span>432 lines (391 sloc)</span>
                <span>14.746 kb</span>
              </div>
              <ul class="button-group actions">
                  <li>
                    <a class="grouped-button file-edit-link minibutton bigger lighter js-rewrite-sha" href="/memcached/memcached/edit/b19b41d968e064902dd585c68582b687e6ccdfc7/hash.c" data-method="post" rel="nofollow" data-hotkey="e"><span>Edit this file</span></a>
                  </li>

                <li>
                  <a href="/memcached/memcached/raw/master/hash.c" class="minibutton btn-raw grouped-button bigger lighter" id="raw-url"><span><span class="icon"></span>Raw</span></a>
                </li>
                  <li>
                    <a href="/memcached/memcached/blame/master/hash.c" class="minibutton btn-blame grouped-button bigger lighter"><span><span class="icon"></span>Blame</span></a>
                  </li>
                <li>
                  <a href="/memcached/memcached/commits/master/hash.c" class="minibutton btn-history grouped-button bigger lighter" rel="nofollow"><span><span class="icon"></span>History</span></a>
                </li>
              </ul>
            </div>
              <div class="data type-c">
      <table cellpadding="0" cellspacing="0" class="lines">
        <tr>
          <td>
            <pre class="line_numbers"><span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>
<span id="L194" rel="#L194">194</span>
<span id="L195" rel="#L195">195</span>
<span id="L196" rel="#L196">196</span>
<span id="L197" rel="#L197">197</span>
<span id="L198" rel="#L198">198</span>
<span id="L199" rel="#L199">199</span>
<span id="L200" rel="#L200">200</span>
<span id="L201" rel="#L201">201</span>
<span id="L202" rel="#L202">202</span>
<span id="L203" rel="#L203">203</span>
<span id="L204" rel="#L204">204</span>
<span id="L205" rel="#L205">205</span>
<span id="L206" rel="#L206">206</span>
<span id="L207" rel="#L207">207</span>
<span id="L208" rel="#L208">208</span>
<span id="L209" rel="#L209">209</span>
<span id="L210" rel="#L210">210</span>
<span id="L211" rel="#L211">211</span>
<span id="L212" rel="#L212">212</span>
<span id="L213" rel="#L213">213</span>
<span id="L214" rel="#L214">214</span>
<span id="L215" rel="#L215">215</span>
<span id="L216" rel="#L216">216</span>
<span id="L217" rel="#L217">217</span>
<span id="L218" rel="#L218">218</span>
<span id="L219" rel="#L219">219</span>
<span id="L220" rel="#L220">220</span>
<span id="L221" rel="#L221">221</span>
<span id="L222" rel="#L222">222</span>
<span id="L223" rel="#L223">223</span>
<span id="L224" rel="#L224">224</span>
<span id="L225" rel="#L225">225</span>
<span id="L226" rel="#L226">226</span>
<span id="L227" rel="#L227">227</span>
<span id="L228" rel="#L228">228</span>
<span id="L229" rel="#L229">229</span>
<span id="L230" rel="#L230">230</span>
<span id="L231" rel="#L231">231</span>
<span id="L232" rel="#L232">232</span>
<span id="L233" rel="#L233">233</span>
<span id="L234" rel="#L234">234</span>
<span id="L235" rel="#L235">235</span>
<span id="L236" rel="#L236">236</span>
<span id="L237" rel="#L237">237</span>
<span id="L238" rel="#L238">238</span>
<span id="L239" rel="#L239">239</span>
<span id="L240" rel="#L240">240</span>
<span id="L241" rel="#L241">241</span>
<span id="L242" rel="#L242">242</span>
<span id="L243" rel="#L243">243</span>
<span id="L244" rel="#L244">244</span>
<span id="L245" rel="#L245">245</span>
<span id="L246" rel="#L246">246</span>
<span id="L247" rel="#L247">247</span>
<span id="L248" rel="#L248">248</span>
<span id="L249" rel="#L249">249</span>
<span id="L250" rel="#L250">250</span>
<span id="L251" rel="#L251">251</span>
<span id="L252" rel="#L252">252</span>
<span id="L253" rel="#L253">253</span>
<span id="L254" rel="#L254">254</span>
<span id="L255" rel="#L255">255</span>
<span id="L256" rel="#L256">256</span>
<span id="L257" rel="#L257">257</span>
<span id="L258" rel="#L258">258</span>
<span id="L259" rel="#L259">259</span>
<span id="L260" rel="#L260">260</span>
<span id="L261" rel="#L261">261</span>
<span id="L262" rel="#L262">262</span>
<span id="L263" rel="#L263">263</span>
<span id="L264" rel="#L264">264</span>
<span id="L265" rel="#L265">265</span>
<span id="L266" rel="#L266">266</span>
<span id="L267" rel="#L267">267</span>
<span id="L268" rel="#L268">268</span>
<span id="L269" rel="#L269">269</span>
<span id="L270" rel="#L270">270</span>
<span id="L271" rel="#L271">271</span>
<span id="L272" rel="#L272">272</span>
<span id="L273" rel="#L273">273</span>
<span id="L274" rel="#L274">274</span>
<span id="L275" rel="#L275">275</span>
<span id="L276" rel="#L276">276</span>
<span id="L277" rel="#L277">277</span>
<span id="L278" rel="#L278">278</span>
<span id="L279" rel="#L279">279</span>
<span id="L280" rel="#L280">280</span>
<span id="L281" rel="#L281">281</span>
<span id="L282" rel="#L282">282</span>
<span id="L283" rel="#L283">283</span>
<span id="L284" rel="#L284">284</span>
<span id="L285" rel="#L285">285</span>
<span id="L286" rel="#L286">286</span>
<span id="L287" rel="#L287">287</span>
<span id="L288" rel="#L288">288</span>
<span id="L289" rel="#L289">289</span>
<span id="L290" rel="#L290">290</span>
<span id="L291" rel="#L291">291</span>
<span id="L292" rel="#L292">292</span>
<span id="L293" rel="#L293">293</span>
<span id="L294" rel="#L294">294</span>
<span id="L295" rel="#L295">295</span>
<span id="L296" rel="#L296">296</span>
<span id="L297" rel="#L297">297</span>
<span id="L298" rel="#L298">298</span>
<span id="L299" rel="#L299">299</span>
<span id="L300" rel="#L300">300</span>
<span id="L301" rel="#L301">301</span>
<span id="L302" rel="#L302">302</span>
<span id="L303" rel="#L303">303</span>
<span id="L304" rel="#L304">304</span>
<span id="L305" rel="#L305">305</span>
<span id="L306" rel="#L306">306</span>
<span id="L307" rel="#L307">307</span>
<span id="L308" rel="#L308">308</span>
<span id="L309" rel="#L309">309</span>
<span id="L310" rel="#L310">310</span>
<span id="L311" rel="#L311">311</span>
<span id="L312" rel="#L312">312</span>
<span id="L313" rel="#L313">313</span>
<span id="L314" rel="#L314">314</span>
<span id="L315" rel="#L315">315</span>
<span id="L316" rel="#L316">316</span>
<span id="L317" rel="#L317">317</span>
<span id="L318" rel="#L318">318</span>
<span id="L319" rel="#L319">319</span>
<span id="L320" rel="#L320">320</span>
<span id="L321" rel="#L321">321</span>
<span id="L322" rel="#L322">322</span>
<span id="L323" rel="#L323">323</span>
<span id="L324" rel="#L324">324</span>
<span id="L325" rel="#L325">325</span>
<span id="L326" rel="#L326">326</span>
<span id="L327" rel="#L327">327</span>
<span id="L328" rel="#L328">328</span>
<span id="L329" rel="#L329">329</span>
<span id="L330" rel="#L330">330</span>
<span id="L331" rel="#L331">331</span>
<span id="L332" rel="#L332">332</span>
<span id="L333" rel="#L333">333</span>
<span id="L334" rel="#L334">334</span>
<span id="L335" rel="#L335">335</span>
<span id="L336" rel="#L336">336</span>
<span id="L337" rel="#L337">337</span>
<span id="L338" rel="#L338">338</span>
<span id="L339" rel="#L339">339</span>
<span id="L340" rel="#L340">340</span>
<span id="L341" rel="#L341">341</span>
<span id="L342" rel="#L342">342</span>
<span id="L343" rel="#L343">343</span>
<span id="L344" rel="#L344">344</span>
<span id="L345" rel="#L345">345</span>
<span id="L346" rel="#L346">346</span>
<span id="L347" rel="#L347">347</span>
<span id="L348" rel="#L348">348</span>
<span id="L349" rel="#L349">349</span>
<span id="L350" rel="#L350">350</span>
<span id="L351" rel="#L351">351</span>
<span id="L352" rel="#L352">352</span>
<span id="L353" rel="#L353">353</span>
<span id="L354" rel="#L354">354</span>
<span id="L355" rel="#L355">355</span>
<span id="L356" rel="#L356">356</span>
<span id="L357" rel="#L357">357</span>
<span id="L358" rel="#L358">358</span>
<span id="L359" rel="#L359">359</span>
<span id="L360" rel="#L360">360</span>
<span id="L361" rel="#L361">361</span>
<span id="L362" rel="#L362">362</span>
<span id="L363" rel="#L363">363</span>
<span id="L364" rel="#L364">364</span>
<span id="L365" rel="#L365">365</span>
<span id="L366" rel="#L366">366</span>
<span id="L367" rel="#L367">367</span>
<span id="L368" rel="#L368">368</span>
<span id="L369" rel="#L369">369</span>
<span id="L370" rel="#L370">370</span>
<span id="L371" rel="#L371">371</span>
<span id="L372" rel="#L372">372</span>
<span id="L373" rel="#L373">373</span>
<span id="L374" rel="#L374">374</span>
<span id="L375" rel="#L375">375</span>
<span id="L376" rel="#L376">376</span>
<span id="L377" rel="#L377">377</span>
<span id="L378" rel="#L378">378</span>
<span id="L379" rel="#L379">379</span>
<span id="L380" rel="#L380">380</span>
<span id="L381" rel="#L381">381</span>
<span id="L382" rel="#L382">382</span>
<span id="L383" rel="#L383">383</span>
<span id="L384" rel="#L384">384</span>
<span id="L385" rel="#L385">385</span>
<span id="L386" rel="#L386">386</span>
<span id="L387" rel="#L387">387</span>
<span id="L388" rel="#L388">388</span>
<span id="L389" rel="#L389">389</span>
<span id="L390" rel="#L390">390</span>
<span id="L391" rel="#L391">391</span>
<span id="L392" rel="#L392">392</span>
<span id="L393" rel="#L393">393</span>
<span id="L394" rel="#L394">394</span>
<span id="L395" rel="#L395">395</span>
<span id="L396" rel="#L396">396</span>
<span id="L397" rel="#L397">397</span>
<span id="L398" rel="#L398">398</span>
<span id="L399" rel="#L399">399</span>
<span id="L400" rel="#L400">400</span>
<span id="L401" rel="#L401">401</span>
<span id="L402" rel="#L402">402</span>
<span id="L403" rel="#L403">403</span>
<span id="L404" rel="#L404">404</span>
<span id="L405" rel="#L405">405</span>
<span id="L406" rel="#L406">406</span>
<span id="L407" rel="#L407">407</span>
<span id="L408" rel="#L408">408</span>
<span id="L409" rel="#L409">409</span>
<span id="L410" rel="#L410">410</span>
<span id="L411" rel="#L411">411</span>
<span id="L412" rel="#L412">412</span>
<span id="L413" rel="#L413">413</span>
<span id="L414" rel="#L414">414</span>
<span id="L415" rel="#L415">415</span>
<span id="L416" rel="#L416">416</span>
<span id="L417" rel="#L417">417</span>
<span id="L418" rel="#L418">418</span>
<span id="L419" rel="#L419">419</span>
<span id="L420" rel="#L420">420</span>
<span id="L421" rel="#L421">421</span>
<span id="L422" rel="#L422">422</span>
<span id="L423" rel="#L423">423</span>
<span id="L424" rel="#L424">424</span>
<span id="L425" rel="#L425">425</span>
<span id="L426" rel="#L426">426</span>
<span id="L427" rel="#L427">427</span>
<span id="L428" rel="#L428">428</span>
<span id="L429" rel="#L429">429</span>
<span id="L430" rel="#L430">430</span>
<span id="L431" rel="#L431">431</span>
</pre>
          </td>
          <td width="100%">
                <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/* -*- Mode: C; tab-width: 4; c-basic-offset: 4; indent-tabs-mode: nil -*- */</span></div><div class='line' id='LC2'><span class="cm">/*</span></div><div class='line' id='LC3'><span class="cm"> * Hash table</span></div><div class='line' id='LC4'><span class="cm"> *</span></div><div class='line' id='LC5'><span class="cm"> * The hash function used here is by Bob Jenkins, 1996:</span></div><div class='line' id='LC6'><span class="cm"> *    &lt;http://burtleburtle.net/bob/hash/doobs.html&gt;</span></div><div class='line' id='LC7'><span class="cm"> *       &quot;By Bob Jenkins, 1996.  bob_jenkins@burtleburtle.net.</span></div><div class='line' id='LC8'><span class="cm"> *       You may use this code any way you wish, private, educational,</span></div><div class='line' id='LC9'><span class="cm"> *       or commercial.  It&#39;s free.&quot;</span></div><div class='line' id='LC10'><span class="cm"> *</span></div><div class='line' id='LC11'><span class="cm"> */</span></div><div class='line' id='LC12'><span class="cp">#include &quot;memcached.h&quot;</span></div><div class='line' id='LC13'><br/></div><div class='line' id='LC14'><span class="cm">/*</span></div><div class='line' id='LC15'><span class="cm"> * Since the hash function does bit manipulation, it needs to know</span></div><div class='line' id='LC16'><span class="cm"> * whether it&#39;s big or little-endian. ENDIAN_LITTLE and ENDIAN_BIG</span></div><div class='line' id='LC17'><span class="cm"> * are set in the configure script.</span></div><div class='line' id='LC18'><span class="cm"> */</span></div><div class='line' id='LC19'><span class="cp">#if ENDIAN_BIG == 1</span></div><div class='line' id='LC20'><span class="cp"># define HASH_LITTLE_ENDIAN 0</span></div><div class='line' id='LC21'><span class="cp"># define HASH_BIG_ENDIAN 1</span></div><div class='line' id='LC22'><span class="cp">#else</span></div><div class='line' id='LC23'><span class="cp"># if ENDIAN_LITTLE == 1</span></div><div class='line' id='LC24'><span class="cp">#  define HASH_LITTLE_ENDIAN 1</span></div><div class='line' id='LC25'><span class="cp">#  define HASH_BIG_ENDIAN 0</span></div><div class='line' id='LC26'><span class="cp"># else</span></div><div class='line' id='LC27'><span class="cp">#  define HASH_LITTLE_ENDIAN 0</span></div><div class='line' id='LC28'><span class="cp">#  define HASH_BIG_ENDIAN 0</span></div><div class='line' id='LC29'><span class="cp"># endif</span></div><div class='line' id='LC30'><span class="cp">#endif</span></div><div class='line' id='LC31'><br/></div><div class='line' id='LC32'><span class="cp">#define rot(x,k) (((x)&lt;&lt;(k)) ^ ((x)&gt;&gt;(32-(k))))</span></div><div class='line' id='LC33'><br/></div><div class='line' id='LC34'><span class="cm">/*</span></div><div class='line' id='LC35'><span class="cm">-------------------------------------------------------------------------------</span></div><div class='line' id='LC36'><span class="cm">mix -- mix 3 32-bit values reversibly.</span></div><div class='line' id='LC37'><br/></div><div class='line' id='LC38'><span class="cm">This is reversible, so any information in (a,b,c) before mix() is</span></div><div class='line' id='LC39'><span class="cm">still in (a,b,c) after mix().</span></div><div class='line' id='LC40'><br/></div><div class='line' id='LC41'><span class="cm">If four pairs of (a,b,c) inputs are run through mix(), or through</span></div><div class='line' id='LC42'><span class="cm">mix() in reverse, there are at least 32 bits of the output that</span></div><div class='line' id='LC43'><span class="cm">are sometimes the same for one pair and different for another pair.</span></div><div class='line' id='LC44'><span class="cm">This was tested for:</span></div><div class='line' id='LC45'><span class="cm">* pairs that differed by one bit, by two bits, in any combination</span></div><div class='line' id='LC46'><span class="cm">  of top bits of (a,b,c), or in any combination of bottom bits of</span></div><div class='line' id='LC47'><span class="cm">  (a,b,c).</span></div><div class='line' id='LC48'><span class="cm">* &quot;differ&quot; is defined as +, -, ^, or ~^.  For + and -, I transformed</span></div><div class='line' id='LC49'><span class="cm">  the output delta to a Gray code (a^(a&gt;&gt;1)) so a string of 1&#39;s (as</span></div><div class='line' id='LC50'><span class="cm">  is commonly produced by subtraction) look like a single 1-bit</span></div><div class='line' id='LC51'><span class="cm">  difference.</span></div><div class='line' id='LC52'><span class="cm">* the base values were pseudorandom, all zero but one bit set, or</span></div><div class='line' id='LC53'><span class="cm">  all zero plus a counter that starts at zero.</span></div><div class='line' id='LC54'><br/></div><div class='line' id='LC55'><span class="cm">Some k values for my &quot;a-=c; a^=rot(c,k); c+=b;&quot; arrangement that</span></div><div class='line' id='LC56'><span class="cm">satisfy this are</span></div><div class='line' id='LC57'><span class="cm">    4  6  8 16 19  4</span></div><div class='line' id='LC58'><span class="cm">    9 15  3 18 27 15</span></div><div class='line' id='LC59'><span class="cm">   14  9  3  7 17  3</span></div><div class='line' id='LC60'><span class="cm">Well, &quot;9 15 3 18 27 15&quot; didn&#39;t quite get 32 bits diffing</span></div><div class='line' id='LC61'><span class="cm">for &quot;differ&quot; defined as + with a one-bit base and a two-bit delta.  I</span></div><div class='line' id='LC62'><span class="cm">used http://burtleburtle.net/bob/hash/avalanche.html to choose</span></div><div class='line' id='LC63'><span class="cm">the operations, constants, and arrangements of the variables.</span></div><div class='line' id='LC64'><br/></div><div class='line' id='LC65'><span class="cm">This does not achieve avalanche.  There are input bits of (a,b,c)</span></div><div class='line' id='LC66'><span class="cm">that fail to affect some output bits of (a,b,c), especially of a.  The</span></div><div class='line' id='LC67'><span class="cm">most thoroughly mixed value is c, but it doesn&#39;t really even achieve</span></div><div class='line' id='LC68'><span class="cm">avalanche in c.</span></div><div class='line' id='LC69'><br/></div><div class='line' id='LC70'><span class="cm">This allows some parallelism.  Read-after-writes are good at doubling</span></div><div class='line' id='LC71'><span class="cm">the number of bits affected, so the goal of mixing pulls in the opposite</span></div><div class='line' id='LC72'><span class="cm">direction as the goal of parallelism.  I did what I could.  Rotates</span></div><div class='line' id='LC73'><span class="cm">seem to cost as much as shifts on every machine I could lay my hands</span></div><div class='line' id='LC74'><span class="cm">on, and rotates are much kinder to the top and bottom bits, so I used</span></div><div class='line' id='LC75'><span class="cm">rotates.</span></div><div class='line' id='LC76'><span class="cm">-------------------------------------------------------------------------------</span></div><div class='line' id='LC77'><span class="cm">*/</span></div><div class='line' id='LC78'><span class="cp">#define mix(a,b,c) \</span></div><div class='line' id='LC79'><span class="cp">{ \</span></div><div class='line' id='LC80'><span class="cp">  a -= c;  a ^= rot(c, 4);  c += b; \</span></div><div class='line' id='LC81'><span class="cp">  b -= a;  b ^= rot(a, 6);  a += c; \</span></div><div class='line' id='LC82'><span class="cp">  c -= b;  c ^= rot(b, 8);  b += a; \</span></div><div class='line' id='LC83'><span class="cp">  a -= c;  a ^= rot(c,16);  c += b; \</span></div><div class='line' id='LC84'><span class="cp">  b -= a;  b ^= rot(a,19);  a += c; \</span></div><div class='line' id='LC85'><span class="cp">  c -= b;  c ^= rot(b, 4);  b += a; \</span></div><div class='line' id='LC86'><span class="cp">}</span></div><div class='line' id='LC87'><br/></div><div class='line' id='LC88'><span class="cm">/*</span></div><div class='line' id='LC89'><span class="cm">-------------------------------------------------------------------------------</span></div><div class='line' id='LC90'><span class="cm">final -- final mixing of 3 32-bit values (a,b,c) into c</span></div><div class='line' id='LC91'><br/></div><div class='line' id='LC92'><span class="cm">Pairs of (a,b,c) values differing in only a few bits will usually</span></div><div class='line' id='LC93'><span class="cm">produce values of c that look totally different.  This was tested for</span></div><div class='line' id='LC94'><span class="cm">* pairs that differed by one bit, by two bits, in any combination</span></div><div class='line' id='LC95'><span class="cm">  of top bits of (a,b,c), or in any combination of bottom bits of</span></div><div class='line' id='LC96'><span class="cm">  (a,b,c).</span></div><div class='line' id='LC97'><span class="cm">* &quot;differ&quot; is defined as +, -, ^, or ~^.  For + and -, I transformed</span></div><div class='line' id='LC98'><span class="cm">  the output delta to a Gray code (a^(a&gt;&gt;1)) so a string of 1&#39;s (as</span></div><div class='line' id='LC99'><span class="cm">  is commonly produced by subtraction) look like a single 1-bit</span></div><div class='line' id='LC100'><span class="cm">  difference.</span></div><div class='line' id='LC101'><span class="cm">* the base values were pseudorandom, all zero but one bit set, or</span></div><div class='line' id='LC102'><span class="cm">  all zero plus a counter that starts at zero.</span></div><div class='line' id='LC103'><br/></div><div class='line' id='LC104'><span class="cm">These constants passed:</span></div><div class='line' id='LC105'><span class="cm"> 14 11 25 16 4 14 24</span></div><div class='line' id='LC106'><span class="cm"> 12 14 25 16 4 14 24</span></div><div class='line' id='LC107'><span class="cm">and these came close:</span></div><div class='line' id='LC108'><span class="cm">  4  8 15 26 3 22 24</span></div><div class='line' id='LC109'><span class="cm"> 10  8 15 26 3 22 24</span></div><div class='line' id='LC110'><span class="cm"> 11  8 15 26 3 22 24</span></div><div class='line' id='LC111'><span class="cm">-------------------------------------------------------------------------------</span></div><div class='line' id='LC112'><span class="cm">*/</span></div><div class='line' id='LC113'><span class="cp">#define final(a,b,c) \</span></div><div class='line' id='LC114'><span class="cp">{ \</span></div><div class='line' id='LC115'><span class="cp">  c ^= b; c -= rot(b,14); \</span></div><div class='line' id='LC116'><span class="cp">  a ^= c; a -= rot(c,11); \</span></div><div class='line' id='LC117'><span class="cp">  b ^= a; b -= rot(a,25); \</span></div><div class='line' id='LC118'><span class="cp">  c ^= b; c -= rot(b,16); \</span></div><div class='line' id='LC119'><span class="cp">  a ^= c; a -= rot(c,4);  \</span></div><div class='line' id='LC120'><span class="cp">  b ^= a; b -= rot(a,14); \</span></div><div class='line' id='LC121'><span class="cp">  c ^= b; c -= rot(b,24); \</span></div><div class='line' id='LC122'><span class="cp">}</span></div><div class='line' id='LC123'><br/></div><div class='line' id='LC124'><span class="cp">#if HASH_LITTLE_ENDIAN == 1</span></div><div class='line' id='LC125'><span class="kt">uint32_t</span> <span class="nf">hash</span><span class="p">(</span></div><div class='line' id='LC126'>&nbsp;&nbsp;<span class="k">const</span> <span class="kt">void</span> <span class="o">*</span><span class="n">key</span><span class="p">,</span>       <span class="cm">/* the key to hash */</span></div><div class='line' id='LC127'>&nbsp;&nbsp;<span class="kt">size_t</span>      <span class="n">length</span><span class="p">,</span>    <span class="cm">/* length of the key */</span></div><div class='line' id='LC128'>&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint32_t</span>    <span class="n">initval</span><span class="p">)</span>   <span class="cm">/* initval */</span></div><div class='line' id='LC129'><span class="p">{</span></div><div class='line' id='LC130'>&nbsp;&nbsp;<span class="kt">uint32_t</span> <span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">;</span>                                          <span class="cm">/* internal state */</span></div><div class='line' id='LC131'>&nbsp;&nbsp;<span class="k">union</span> <span class="p">{</span> <span class="k">const</span> <span class="kt">void</span> <span class="o">*</span><span class="n">ptr</span><span class="p">;</span> <span class="kt">size_t</span> <span class="n">i</span><span class="p">;</span> <span class="p">}</span> <span class="n">u</span><span class="p">;</span>     <span class="cm">/* needed for Mac Powerbook G4 */</span></div><div class='line' id='LC132'><br/></div><div class='line' id='LC133'>&nbsp;&nbsp;<span class="cm">/* Set up the internal state */</span></div><div class='line' id='LC134'>&nbsp;&nbsp;<span class="n">a</span> <span class="o">=</span> <span class="n">b</span> <span class="o">=</span> <span class="n">c</span> <span class="o">=</span> <span class="mh">0xdeadbeef</span> <span class="o">+</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">length</span><span class="p">)</span> <span class="o">+</span> <span class="n">initval</span><span class="p">;</span></div><div class='line' id='LC135'><br/></div><div class='line' id='LC136'>&nbsp;&nbsp;<span class="n">u</span><span class="p">.</span><span class="n">ptr</span> <span class="o">=</span> <span class="n">key</span><span class="p">;</span></div><div class='line' id='LC137'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">HASH_LITTLE_ENDIAN</span> <span class="o">&amp;&amp;</span> <span class="p">((</span><span class="n">u</span><span class="p">.</span><span class="n">i</span> <span class="o">&amp;</span> <span class="mh">0x3</span><span class="p">)</span> <span class="o">==</span> <span class="mi">0</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC138'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint32_t</span> <span class="o">*</span><span class="n">k</span> <span class="o">=</span> <span class="n">key</span><span class="p">;</span>                           <span class="cm">/* read 32-bit chunks */</span></div><div class='line' id='LC139'><span class="cp">#ifdef VALGRIND</span></div><div class='line' id='LC140'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint8_t</span>  <span class="o">*</span><span class="n">k8</span><span class="p">;</span></div><div class='line' id='LC141'><span class="cp">#endif </span><span class="cm">/* ifdef VALGRIND */</span><span class="cp"></span></div><div class='line' id='LC142'><br/></div><div class='line' id='LC143'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*------ all but last block: aligned reads and affect 32 bits of (a,b,c) */</span></div><div class='line' id='LC144'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">length</span> <span class="o">&gt;</span> <span class="mi">12</span><span class="p">)</span></div><div class='line' id='LC145'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC146'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC147'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span></div><div class='line' id='LC148'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span></div><div class='line' id='LC149'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mix</span><span class="p">(</span><span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">);</span></div><div class='line' id='LC150'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">length</span> <span class="o">-=</span> <span class="mi">12</span><span class="p">;</span></div><div class='line' id='LC151'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">k</span> <span class="o">+=</span> <span class="mi">3</span><span class="p">;</span></div><div class='line' id='LC152'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC153'><br/></div><div class='line' id='LC154'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*----------------------------- handle the last (probably partial) block */</span></div><div class='line' id='LC155'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*</span></div><div class='line' id='LC156'><span class="cm">     * &quot;k[2]&amp;0xffffff&quot; actually reads beyond the end of the string, but</span></div><div class='line' id='LC157'><span class="cm">     * then masks off the part it&#39;s not allowed to read.  Because the</span></div><div class='line' id='LC158'><span class="cm">     * string is aligned, the masked-off tail is in the same word as the</span></div><div class='line' id='LC159'><span class="cm">     * rest of the string.  Every machine with memory protection I&#39;ve seen</span></div><div class='line' id='LC160'><span class="cm">     * does it on word boundaries, so is OK with this.  But VALGRIND will</span></div><div class='line' id='LC161'><span class="cm">     * still catch it and complain.  The masking trick does make the hash</span></div><div class='line' id='LC162'><span class="cm">     * noticably faster for short strings (like English words).</span></div><div class='line' id='LC163'><span class="cm">     */</span></div><div class='line' id='LC164'><span class="cp">#ifndef VALGRIND</span></div><div class='line' id='LC165'><br/></div><div class='line' id='LC166'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">switch</span><span class="p">(</span><span class="n">length</span><span class="p">)</span></div><div class='line' id='LC167'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC168'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">12</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC169'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">11</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffffff</span><span class="p">;</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC170'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">10</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffff</span><span class="p">;</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC171'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">9</span> : <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xff</span><span class="p">;</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC172'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">8</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC173'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">7</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffffff</span><span class="p">;</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC174'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">6</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffff</span><span class="p">;</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC175'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">5</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xff</span><span class="p">;</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC176'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC177'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffffff</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC178'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffff</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC179'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xff</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC180'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">0</span> : <span class="k">return</span> <span class="n">c</span><span class="p">;</span>  <span class="cm">/* zero length strings require no mixing */</span></div><div class='line' id='LC181'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC182'><br/></div><div class='line' id='LC183'><span class="cp">#else </span><span class="cm">/* make valgrind happy */</span><span class="cp"></span></div><div class='line' id='LC184'><br/></div><div class='line' id='LC185'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">k8</span> <span class="o">=</span> <span class="p">(</span><span class="k">const</span> <span class="kt">uint8_t</span> <span class="o">*</span><span class="p">)</span><span class="n">k</span><span class="p">;</span></div><div class='line' id='LC186'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">switch</span><span class="p">(</span><span class="n">length</span><span class="p">)</span></div><div class='line' id='LC187'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC188'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">12</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC189'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">11</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">10</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>  <span class="cm">/* fall through */</span></div><div class='line' id='LC190'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">10</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">9</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span>    <span class="cm">/* fall through */</span></div><div class='line' id='LC191'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">9</span> : <span class="n">c</span><span class="o">+=</span><span class="n">k8</span><span class="p">[</span><span class="mi">8</span><span class="p">];</span>                   <span class="cm">/* fall through */</span></div><div class='line' id='LC192'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">8</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC193'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">7</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">6</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>   <span class="cm">/* fall through */</span></div><div class='line' id='LC194'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">6</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">5</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span>    <span class="cm">/* fall through */</span></div><div class='line' id='LC195'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">5</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k8</span><span class="p">[</span><span class="mi">4</span><span class="p">];</span>                   <span class="cm">/* fall through */</span></div><div class='line' id='LC196'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC197'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">2</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>   <span class="cm">/* fall through */</span></div><div class='line' id='LC198'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span>    <span class="cm">/* fall through */</span></div><div class='line' id='LC199'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k8</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC200'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">0</span> : <span class="k">return</span> <span class="n">c</span><span class="p">;</span>  <span class="cm">/* zero length strings require no mixing */</span></div><div class='line' id='LC201'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC202'><br/></div><div class='line' id='LC203'><span class="cp">#endif </span><span class="cm">/* !valgrind */</span><span class="cp"></span></div><div class='line' id='LC204'><br/></div><div class='line' id='LC205'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">HASH_LITTLE_ENDIAN</span> <span class="o">&amp;&amp;</span> <span class="p">((</span><span class="n">u</span><span class="p">.</span><span class="n">i</span> <span class="o">&amp;</span> <span class="mh">0x1</span><span class="p">)</span> <span class="o">==</span> <span class="mi">0</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC206'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint16_t</span> <span class="o">*</span><span class="n">k</span> <span class="o">=</span> <span class="n">key</span><span class="p">;</span>                           <span class="cm">/* read 16-bit chunks */</span></div><div class='line' id='LC207'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint8_t</span>  <span class="o">*</span><span class="n">k8</span><span class="p">;</span></div><div class='line' id='LC208'><br/></div><div class='line' id='LC209'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*--------------- all but last block: aligned reads and different mixing */</span></div><div class='line' id='LC210'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">length</span> <span class="o">&gt;</span> <span class="mi">12</span><span class="p">)</span></div><div class='line' id='LC211'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC212'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">+</span> <span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC213'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">+</span> <span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">3</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC214'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">4</span><span class="p">]</span> <span class="o">+</span> <span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">5</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC215'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mix</span><span class="p">(</span><span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">);</span></div><div class='line' id='LC216'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">length</span> <span class="o">-=</span> <span class="mi">12</span><span class="p">;</span></div><div class='line' id='LC217'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">k</span> <span class="o">+=</span> <span class="mi">6</span><span class="p">;</span></div><div class='line' id='LC218'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC219'><br/></div><div class='line' id='LC220'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*----------------------------- handle the last (probably partial) block */</span></div><div class='line' id='LC221'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">k8</span> <span class="o">=</span> <span class="p">(</span><span class="k">const</span> <span class="kt">uint8_t</span> <span class="o">*</span><span class="p">)</span><span class="n">k</span><span class="p">;</span></div><div class='line' id='LC222'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">switch</span><span class="p">(</span><span class="n">length</span><span class="p">)</span></div><div class='line' id='LC223'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC224'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">12</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">4</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">5</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC225'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">3</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC226'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC227'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC228'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">11</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">10</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>     <span class="cm">/* @fallthrough */</span></div><div class='line' id='LC229'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">10</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">4</span><span class="p">];</span>                       <span class="cm">/* @fallthrough@ */</span></div><div class='line' id='LC230'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">3</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC231'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC232'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC233'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">9</span> : <span class="n">c</span><span class="o">+=</span><span class="n">k8</span><span class="p">[</span><span class="mi">8</span><span class="p">];</span>                      <span class="cm">/* @fallthrough */</span></div><div class='line' id='LC234'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">8</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">3</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC235'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC236'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC237'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">7</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">6</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>      <span class="cm">/* @fallthrough */</span></div><div class='line' id='LC238'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">6</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span></div><div class='line' id='LC239'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC240'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC241'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">5</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k8</span><span class="p">[</span><span class="mi">4</span><span class="p">];</span>                      <span class="cm">/* @fallthrough */</span></div><div class='line' id='LC242'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">+</span><span class="p">(((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC243'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC244'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">2</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>      <span class="cm">/* @fallthrough */</span></div><div class='line' id='LC245'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC246'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC247'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k8</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC248'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC249'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">0</span> : <span class="k">return</span> <span class="n">c</span><span class="p">;</span>  <span class="cm">/* zero length strings require no mixing */</span></div><div class='line' id='LC250'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC251'><br/></div><div class='line' id='LC252'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>                        <span class="cm">/* need to read the key one byte at a time */</span></div><div class='line' id='LC253'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint8_t</span> <span class="o">*</span><span class="n">k</span> <span class="o">=</span> <span class="n">key</span><span class="p">;</span></div><div class='line' id='LC254'><br/></div><div class='line' id='LC255'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*--------------- all but the last block: affect some 32 bits of (a,b,c) */</span></div><div class='line' id='LC256'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">length</span> <span class="o">&gt;</span> <span class="mi">12</span><span class="p">)</span></div><div class='line' id='LC257'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC258'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC259'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC260'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC261'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">3</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC262'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">4</span><span class="p">];</span></div><div class='line' id='LC263'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">5</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC264'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">6</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC265'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">7</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC266'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">8</span><span class="p">];</span></div><div class='line' id='LC267'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">9</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC268'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">10</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC269'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">11</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC270'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mix</span><span class="p">(</span><span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">);</span></div><div class='line' id='LC271'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">length</span> <span class="o">-=</span> <span class="mi">12</span><span class="p">;</span></div><div class='line' id='LC272'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">k</span> <span class="o">+=</span> <span class="mi">12</span><span class="p">;</span></div><div class='line' id='LC273'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC274'><br/></div><div class='line' id='LC275'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*-------------------------------- last block: affect all 32 bits of (c) */</span></div><div class='line' id='LC276'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">switch</span><span class="p">(</span><span class="n">length</span><span class="p">)</span>                   <span class="cm">/* all the case statements fall through */</span></div><div class='line' id='LC277'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC278'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">12</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">11</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC279'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">11</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">10</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC280'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">10</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">9</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC281'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">9</span> : <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">8</span><span class="p">];</span></div><div class='line' id='LC282'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">8</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">7</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC283'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">7</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">6</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC284'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">6</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">5</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC285'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">5</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">4</span><span class="p">];</span></div><div class='line' id='LC286'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">3</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC287'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC288'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC289'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC290'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC291'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">0</span> : <span class="k">return</span> <span class="n">c</span><span class="p">;</span>  <span class="cm">/* zero length strings require no mixing */</span></div><div class='line' id='LC292'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC293'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC294'><br/></div><div class='line' id='LC295'>&nbsp;&nbsp;<span class="n">final</span><span class="p">(</span><span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">);</span></div><div class='line' id='LC296'>&nbsp;&nbsp;<span class="k">return</span> <span class="n">c</span><span class="p">;</span>             <span class="cm">/* zero length strings require no mixing */</span></div><div class='line' id='LC297'><span class="p">}</span></div><div class='line' id='LC298'><br/></div><div class='line' id='LC299'><span class="cp">#elif HASH_BIG_ENDIAN == 1</span></div><div class='line' id='LC300'><span class="cm">/*</span></div><div class='line' id='LC301'><span class="cm"> * hashbig():</span></div><div class='line' id='LC302'><span class="cm"> * This is the same as hashword() on big-endian machines.  It is different</span></div><div class='line' id='LC303'><span class="cm"> * from hashlittle() on all machines.  hashbig() takes advantage of</span></div><div class='line' id='LC304'><span class="cm"> * big-endian byte ordering.</span></div><div class='line' id='LC305'><span class="cm"> */</span></div><div class='line' id='LC306'><span class="kt">uint32_t</span> <span class="nf">hash</span><span class="p">(</span> <span class="k">const</span> <span class="kt">void</span> <span class="o">*</span><span class="n">key</span><span class="p">,</span> <span class="kt">size_t</span> <span class="n">length</span><span class="p">,</span> <span class="k">const</span> <span class="kt">uint32_t</span> <span class="n">initval</span><span class="p">)</span></div><div class='line' id='LC307'><span class="p">{</span></div><div class='line' id='LC308'>&nbsp;&nbsp;<span class="kt">uint32_t</span> <span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">;</span></div><div class='line' id='LC309'>&nbsp;&nbsp;<span class="k">union</span> <span class="p">{</span> <span class="k">const</span> <span class="kt">void</span> <span class="o">*</span><span class="n">ptr</span><span class="p">;</span> <span class="kt">size_t</span> <span class="n">i</span><span class="p">;</span> <span class="p">}</span> <span class="n">u</span><span class="p">;</span> <span class="cm">/* to cast key to (size_t) happily */</span></div><div class='line' id='LC310'><br/></div><div class='line' id='LC311'>&nbsp;&nbsp;<span class="cm">/* Set up the internal state */</span></div><div class='line' id='LC312'>&nbsp;&nbsp;<span class="n">a</span> <span class="o">=</span> <span class="n">b</span> <span class="o">=</span> <span class="n">c</span> <span class="o">=</span> <span class="mh">0xdeadbeef</span> <span class="o">+</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">length</span><span class="p">)</span> <span class="o">+</span> <span class="n">initval</span><span class="p">;</span></div><div class='line' id='LC313'><br/></div><div class='line' id='LC314'>&nbsp;&nbsp;<span class="n">u</span><span class="p">.</span><span class="n">ptr</span> <span class="o">=</span> <span class="n">key</span><span class="p">;</span></div><div class='line' id='LC315'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">HASH_BIG_ENDIAN</span> <span class="o">&amp;&amp;</span> <span class="p">((</span><span class="n">u</span><span class="p">.</span><span class="n">i</span> <span class="o">&amp;</span> <span class="mh">0x3</span><span class="p">)</span> <span class="o">==</span> <span class="mi">0</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC316'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint32_t</span> <span class="o">*</span><span class="n">k</span> <span class="o">=</span> <span class="n">key</span><span class="p">;</span>                           <span class="cm">/* read 32-bit chunks */</span></div><div class='line' id='LC317'><span class="cp">#ifdef VALGRIND</span></div><div class='line' id='LC318'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint8_t</span>  <span class="o">*</span><span class="n">k8</span><span class="p">;</span></div><div class='line' id='LC319'><span class="cp">#endif </span><span class="cm">/* ifdef VALGRIND */</span><span class="cp"></span></div><div class='line' id='LC320'><br/></div><div class='line' id='LC321'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*------ all but last block: aligned reads and affect 32 bits of (a,b,c) */</span></div><div class='line' id='LC322'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">length</span> <span class="o">&gt;</span> <span class="mi">12</span><span class="p">)</span></div><div class='line' id='LC323'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC324'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC325'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span></div><div class='line' id='LC326'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span></div><div class='line' id='LC327'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mix</span><span class="p">(</span><span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">);</span></div><div class='line' id='LC328'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">length</span> <span class="o">-=</span> <span class="mi">12</span><span class="p">;</span></div><div class='line' id='LC329'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">k</span> <span class="o">+=</span> <span class="mi">3</span><span class="p">;</span></div><div class='line' id='LC330'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC331'><br/></div><div class='line' id='LC332'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*----------------------------- handle the last (probably partial) block */</span></div><div class='line' id='LC333'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*</span></div><div class='line' id='LC334'><span class="cm">     * &quot;k[2]&lt;&lt;8&quot; actually reads beyond the end of the string, but</span></div><div class='line' id='LC335'><span class="cm">     * then shifts out the part it&#39;s not allowed to read.  Because the</span></div><div class='line' id='LC336'><span class="cm">     * string is aligned, the illegal read is in the same word as the</span></div><div class='line' id='LC337'><span class="cm">     * rest of the string.  Every machine with memory protection I&#39;ve seen</span></div><div class='line' id='LC338'><span class="cm">     * does it on word boundaries, so is OK with this.  But VALGRIND will</span></div><div class='line' id='LC339'><span class="cm">     * still catch it and complain.  The masking trick does make the hash</span></div><div class='line' id='LC340'><span class="cm">     * noticably faster for short strings (like English words).</span></div><div class='line' id='LC341'><span class="cm">     */</span></div><div class='line' id='LC342'><span class="cp">#ifndef VALGRIND</span></div><div class='line' id='LC343'><br/></div><div class='line' id='LC344'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">switch</span><span class="p">(</span><span class="n">length</span><span class="p">)</span></div><div class='line' id='LC345'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC346'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">12</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC347'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">11</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffffff00</span><span class="p">;</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC348'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">10</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffff0000</span><span class="p">;</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC349'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">9</span> : <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xff000000</span><span class="p">;</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC350'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">8</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC351'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">7</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffffff00</span><span class="p">;</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC352'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">6</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffff0000</span><span class="p">;</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC353'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">5</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xff000000</span><span class="p">;</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC354'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC355'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffffff00</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC356'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xffff0000</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC357'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span><span class="o">&amp;</span><span class="mh">0xff000000</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC358'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">0</span> : <span class="k">return</span> <span class="n">c</span><span class="p">;</span>              <span class="cm">/* zero length strings require no mixing */</span></div><div class='line' id='LC359'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC360'><br/></div><div class='line' id='LC361'><span class="cp">#else  </span><span class="cm">/* make valgrind happy */</span><span class="cp"></span></div><div class='line' id='LC362'><br/></div><div class='line' id='LC363'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">k8</span> <span class="o">=</span> <span class="p">(</span><span class="k">const</span> <span class="kt">uint8_t</span> <span class="o">*</span><span class="p">)</span><span class="n">k</span><span class="p">;</span></div><div class='line' id='LC364'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">switch</span><span class="p">(</span><span class="n">length</span><span class="p">)</span>                   <span class="cm">/* all the case statements fall through */</span></div><div class='line' id='LC365'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC366'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">12</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span> <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC367'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">11</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">10</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span>  <span class="cm">/* fall through */</span></div><div class='line' id='LC368'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">10</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">9</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>  <span class="cm">/* fall through */</span></div><div class='line' id='LC369'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">9</span> : <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">8</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span>  <span class="cm">/* fall through */</span></div><div class='line' id='LC370'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">8</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span> <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC371'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">7</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">6</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span>   <span class="cm">/* fall through */</span></div><div class='line' id='LC372'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">6</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">5</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>  <span class="cm">/* fall through */</span></div><div class='line' id='LC373'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">5</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">4</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span>  <span class="cm">/* fall through */</span></div><div class='line' id='LC374'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC375'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">2</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span>   <span class="cm">/* fall through */</span></div><div class='line' id='LC376'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span>  <span class="cm">/* fall through */</span></div><div class='line' id='LC377'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k8</span><span class="p">[</span><span class="mi">0</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC378'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">0</span> : <span class="k">return</span> <span class="n">c</span><span class="p">;</span></div><div class='line' id='LC379'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC380'><br/></div><div class='line' id='LC381'><span class="cp">#endif </span><span class="cm">/* !VALGRIND */</span><span class="cp"></span></div><div class='line' id='LC382'><br/></div><div class='line' id='LC383'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>                        <span class="cm">/* need to read the key one byte at a time */</span></div><div class='line' id='LC384'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="kt">uint8_t</span> <span class="o">*</span><span class="n">k</span> <span class="o">=</span> <span class="n">key</span><span class="p">;</span></div><div class='line' id='LC385'><br/></div><div class='line' id='LC386'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*--------------- all but the last block: affect some 32 bits of (a,b,c) */</span></div><div class='line' id='LC387'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">length</span> <span class="o">&gt;</span> <span class="mi">12</span><span class="p">)</span></div><div class='line' id='LC388'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC389'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC390'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC391'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC392'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">3</span><span class="p">]);</span></div><div class='line' id='LC393'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">4</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC394'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">5</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC395'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">6</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC396'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">7</span><span class="p">]);</span></div><div class='line' id='LC397'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">8</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC398'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">9</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC399'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">10</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC400'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">+=</span> <span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">11</span><span class="p">]);</span></div><div class='line' id='LC401'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mix</span><span class="p">(</span><span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">);</span></div><div class='line' id='LC402'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">length</span> <span class="o">-=</span> <span class="mi">12</span><span class="p">;</span></div><div class='line' id='LC403'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">k</span> <span class="o">+=</span> <span class="mi">12</span><span class="p">;</span></div><div class='line' id='LC404'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC405'><br/></div><div class='line' id='LC406'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*-------------------------------- last block: affect all 32 bits of (c) */</span></div><div class='line' id='LC407'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">switch</span><span class="p">(</span><span class="n">length</span><span class="p">)</span>                   <span class="cm">/* all the case statements fall through */</span></div><div class='line' id='LC408'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC409'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">12</span>: <span class="n">c</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">11</span><span class="p">];</span></div><div class='line' id='LC410'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">11</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">10</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC411'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">10</span>: <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">9</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC412'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">9</span> : <span class="n">c</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">8</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC413'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">8</span> : <span class="n">b</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">7</span><span class="p">];</span></div><div class='line' id='LC414'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">7</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">6</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC415'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">6</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">5</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC416'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">5</span> : <span class="n">b</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">4</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC417'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span> : <span class="n">a</span><span class="o">+=</span><span class="n">k</span><span class="p">[</span><span class="mi">3</span><span class="p">];</span></div><div class='line' id='LC418'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">2</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">8</span><span class="p">;</span></div><div class='line' id='LC419'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">1</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">16</span><span class="p">;</span></div><div class='line' id='LC420'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span> : <span class="n">a</span><span class="o">+=</span><span class="p">((</span><span class="kt">uint32_t</span><span class="p">)</span><span class="n">k</span><span class="p">[</span><span class="mi">0</span><span class="p">])</span><span class="o">&lt;&lt;</span><span class="mi">24</span><span class="p">;</span></div><div class='line' id='LC421'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC422'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">0</span> : <span class="k">return</span> <span class="n">c</span><span class="p">;</span></div><div class='line' id='LC423'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC424'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC425'><br/></div><div class='line' id='LC426'>&nbsp;&nbsp;<span class="n">final</span><span class="p">(</span><span class="n">a</span><span class="p">,</span><span class="n">b</span><span class="p">,</span><span class="n">c</span><span class="p">);</span></div><div class='line' id='LC427'>&nbsp;&nbsp;<span class="k">return</span> <span class="n">c</span><span class="p">;</span></div><div class='line' id='LC428'><span class="p">}</span></div><div class='line' id='LC429'><span class="cp">#else </span><span class="cm">/* HASH_XXX_ENDIAN == 1 */</span><span class="cp"></span></div><div class='line' id='LC430'><span class="cp">#error Must define HASH_BIG_ENDIAN or HASH_LITTLE_ENDIAN</span></div><div class='line' id='LC431'><span class="cp">#endif </span><span class="cm">/* HASH_XXX_ENDIAN == 1 */</span><span class="cp"></span></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>
      </div>
    </div>

  </div>

<div class="frame frame-loading large-loading-area" style="display:none;" data-tree-list-url="/memcached/memcached/tree-list/b19b41d968e064902dd585c68582b687e6ccdfc7" data-blob-url-prefix="/memcached/memcached/blob/b19b41d968e064902dd585c68582b687e6ccdfc7">
  <img src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-64.gif?1329872008" height="64" width="64">
</div>

      </div>
      <div class="context-overlay"></div>
    </div>

      <div id="footer-push"></div><!-- hack for sticky footer -->
    </div><!-- end of wrapper - hack for sticky footer -->

      <!-- footer -->
      <div id="footer" >
        
  <div class="upper_footer">
     <div class="container clearfix">

       <!--[if IE]><h4 id="blacktocat_ie">GitHub Links</h4><![endif]-->
       <![if !IE]><h4 id="blacktocat">GitHub Links</h4><![endif]>

       <ul class="footer_nav">
         <h4>GitHub</h4>
         <li><a href="https://github.com/about">About</a></li>
         <li><a href="https://github.com/blog">Blog</a></li>
         <li><a href="https://github.com/features">Features</a></li>
         <li><a href="https://github.com/contact">Contact &amp; Support</a></li>
         <li><a href="https://github.com/training">Training</a></li>
         <li><a href="http://enterprise.github.com/">GitHub Enterprise</a></li>
         <li><a href="http://status.github.com/">Site Status</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Tools</h4>
         <li><a href="http://get.gaug.es/">Gauges: Analyze web traffic</a></li>
         <li><a href="http://speakerdeck.com">Speaker Deck: Presentations</a></li>
         <li><a href="https://gist.github.com">Gist: Code snippets</a></li>
         <li><a href="http://mac.github.com/">GitHub for Mac</a></li>
         <li><a href="http://windows.github.com/">GitHub for Windows</a></li>
         <li><a href="http://mobile.github.com/">Issues for iPhone</a></li>
         <li><a href="http://jobs.github.com/">Job Board</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Extras</h4>
         <li><a href="http://shop.github.com/">GitHub Shop</a></li>
         <li><a href="http://octodex.github.com/">The Octodex</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Documentation</h4>
         <li><a href="http://help.github.com/">GitHub Help</a></li>
         <li><a href="http://developer.github.com/">Developer API</a></li>
         <li><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></li>
         <li><a href="http://pages.github.com/">GitHub Pages</a></li>
       </ul>

     </div><!-- /.site -->
  </div><!-- /.upper_footer -->

<div class="lower_footer">
  <div class="container clearfix">
    <!--[if IE]><div id="legal_ie"><![endif]-->
    <![if !IE]><div id="legal"><![endif]>
      <ul>
          <li><a href="https://github.com/site/terms">Terms of Service</a></li>
          <li><a href="https://github.com/site/privacy">Privacy</a></li>
          <li><a href="https://github.com/security">Security</a></li>
      </ul>

      <p>&copy; 2012 <span title="0.05708s from fe4.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
    </div><!-- /#legal or /#legal_ie-->

      <div class="sponsor">
        <a href="http://www.rackspace.com" class="logo">
          <img alt="Dedicated Server" height="36" src="https://a248.e.akamai.net/assets.github.com/images/modules/footer/rackspaces_logo.png?1329521040" width="38" />
        </a>
        Powered by the <a href="http://www.rackspace.com ">Dedicated
        Servers</a> and<br/> <a href="http://www.rackspacecloud.com">Cloud
        Computing</a> of Rackspace Hosting<span>&reg;</span>
      </div>
  </div><!-- /.site -->
</div><!-- /.lower_footer -->

      </div><!-- /#footer -->

    

<div id="keyboard_shortcuts_pane" class="instapaper_ignore readability-extra" style="display:none">
  <h2>Keyboard Shortcuts <small><a href="#" class="js-see-all-keyboard-shortcuts">(see all)</a></small></h2>

  <div class="columns threecols">
    <div class="column first">
      <h3>Site wide shortcuts</h3>
      <dl class="keyboard-mappings">
        <dt>s</dt>
        <dd>Focus site search</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>?</dt>
        <dd>Bring up this help dialog</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column middle" style='display:none'>
      <h3>Commit list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>c <em>or</em> o <em>or</em> enter</dt>
        <dd>Open commit</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>y</dt>
        <dd>Expand URL to its canonical form</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column last" style='display:none'>
      <h3>Pull request list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>o <em>or</em> enter</dt>
        <dd>Open issue</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
        <dd>Submit comment</dd>
      </dl>
    </div><!-- /.columns.last -->

  </div><!-- /.columns.equacols -->

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Issues</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>x</dt>
          <dd>Toggle selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
          <dd>Submit comment</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>c</dt>
          <dd>Create issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Create label</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>i</dt>
          <dd>Back to inbox</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>u</dt>
          <dd>Back to issues</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>/</dt>
          <dd>Focus issues search</dd>
        </dl>
      </div>
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Issues Dashboard</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Network Graph</h3>
    <div class="columns equacols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt><span class="badmono">←</span> <em>or</em> h</dt>
          <dd>Scroll left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">→</span> <em>or</em> l</dt>
          <dd>Scroll right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↑</span> <em>or</em> k</dt>
          <dd>Scroll up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↓</span> <em>or</em> j</dt>
          <dd>Scroll down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Toggle visibility of head labels</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">←</span> <em>or</em> shift h</dt>
          <dd>Scroll all the way left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">→</span> <em>or</em> shift l</dt>
          <dd>Scroll all the way right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↑</span> <em>or</em> shift k</dt>
          <dd>Scroll all the way up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↓</span> <em>or</em> shift j</dt>
          <dd>Scroll all the way down</dd>
        </dl>
      </div><!-- /.column.last -->
    </div>
  </div>

  <div >
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first" >
        <h3>Source Code Browsing</h3>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Activates the file finder</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Jump to line</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>w</dt>
          <dd>Switch branch/tag</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Expand URL to its canonical form</dd>
        </dl>
      </div>
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first">
        <h3>Browsing Commits</h3>
        <dl class="keyboard-mappings">
          <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
          <dd>Submit comment</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>escape</dt>
          <dd>Close form</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>p</dt>
          <dd>Parent commit</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o</dt>
          <dd>Other parent commit</dd>
        </dl>
      </div>
    </div>
  </div>
</div>

    <div id="markdown-help" class="instapaper_ignore readability-extra">
  <h2>Markdown Cheat Sheet</h2>

  <div class="cheatsheet-content">

  <div class="mod">
    <div class="col">
      <h3>Format Text</h3>
      <p>Headers</p>
      <pre>
# This is an &lt;h1&gt; tag
## This is an &lt;h2&gt; tag
###### This is an &lt;h6&gt; tag</pre>
     <p>Text styles</p>
     <pre>
*This text will be italic*
_This will also be italic_
**This text will be bold**
__This will also be bold__

*You **can** combine them*
</pre>
    </div>
    <div class="col">
      <h3>Lists</h3>
      <p>Unordered</p>
      <pre>
* Item 1
* Item 2
  * Item 2a
  * Item 2b</pre>
     <p>Ordered</p>
     <pre>
1. Item 1
2. Item 2
3. Item 3
   * Item 3a
   * Item 3b</pre>
    </div>
    <div class="col">
      <h3>Miscellaneous</h3>
      <p>Images</p>
      <pre>
![GitHub Logo](/images/logo.png)
Format: ![Alt Text](url)
</pre>
     <p>Links</p>
     <pre>
http://github.com - automatic!
[GitHub](http://github.com)</pre>
<p>Blockquotes</p>
     <pre>
As Kanye West said:

> We're living the future so
> the present is our past.
</pre>
    </div>
  </div>
  <div class="rule"></div>

  <h3>Code Examples in Markdown</h3>
  <div class="col">
      <p>Syntax highlighting with <a href="http://github.github.com/github-flavored-markdown/" title="GitHub Flavored Markdown" target="_blank">GFM</a></p>
      <pre>
```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```</pre>
    </div>
    <div class="col">
      <p>Or, indent your code 4 spaces</p>
      <pre>
Here is a Python code example
without syntax highlighting:

    def foo:
      if not bar:
        return true</pre>
    </div>
    <div class="col">
      <p>Inline code for comments</p>
      <pre>
I think you should use an
`&lt;addr&gt;` element here instead.</pre>
    </div>
  </div>

  </div>
</div>


    <div class="ajax-error-message">
      <p><span class="mini-icon exclamation"></span> Something went wrong with that request. Please try again. <a href="javascript:;" class="ajax-error-dismiss">Dismiss</a></p>
    </div>

    <div id="logo-popup">
      <h2>Looking for the GitHub logo?</h2>
      <ul>
        <li>
          <h4>GitHub Logo</h4>
          <a href="http://github-media-downloads.s3.amazonaws.com/GitHub_Logos.zip"><img alt="Github_logo" src="https://a248.e.akamai.net/assets.github.com/images/modules/about_page/github_logo.png?1306884373" /></a>
          <a href="http://github-media-downloads.s3.amazonaws.com/GitHub_Logos.zip" class="minibutton btn-download download"><span class="icon"></span>Download</a>
        </li>
        <li>
          <h4>The Octocat</h4>
          <a href="http://github-media-downloads.s3.amazonaws.com/Octocats.zip"><img alt="Octocat" src="https://a248.e.akamai.net/assets.github.com/images/modules/about_page/octocat.png?1306884373" /></a>
          <a href="http://github-media-downloads.s3.amazonaws.com/Octocats.zip" class="minibutton btn-download download"><span class="icon"></span>Download</a>
        </li>
      </ul>
    </div>

    
    
    
    <span id='server_response_time' data-time='0.05907' data-host='fe4'></span>
  </body>
</html>


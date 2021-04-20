<?php
    session_start();
        // tracks user session
    include "includes/db_handler.php";
        // calls client registration handler file
    include "main/header.php";
        // extends header file
?>
    <!-- Header -->
    <header id="header" class="header">
        <div class="header-content">
            <div class="container">
                <div class="row">
                    <div class="col-lg-12">
                        <div class="text-container">
                            <h1><span id="js-rotating" class="special"> AAFCS</span> System</h1>
                            <p class="p-heading p-large"><span class="special-info">Controlled</span> Agriculture and Farm <span class="special-info">Distant Monitoring</span> using internet supported devices made easier.</p>
                            <!-- <p class="p-heading p-large"><span class="special-info">AAFCS</span> system makes agriculture and controlled irrigation simplified</p> -->
                            <a class=" btn btn-solid-lg page-scroll" href="#intro">DISCOVER</a>
                        </div>
                    </div> <!-- end of col -->
                </div> <!-- end of row -->
            </div> <!-- end of container -->
        </div> <!-- end of header-content -->
    </header> <!-- end of header -->
    <!-- end of header -->

    <!-- Intro -->
    <div id="intro" class="basic-1">
        <div class="container">
            <div class="msg_section mb-2">
              <?php
                  echo display_error();
                  // ----error flag notifiers
              ?>
            </div>
            <div class="row">
                <div class="col-lg-5">
                    <div class="text-container">
                        <div class="section-title">INTRODUCTION</div>
                        <p style="color: #999;"><span class="special2">AAFCS</span> refers to <span class="special2">A</span>utomated <span class="special2">A</span>griculture <span class="special2">F</span>arm <span class="special2">C</span>ontrol <span class="special2">S</span>ystem.</p>
                        <p class="">It is an <span class="special2">IoT</span> based project that constitutes of a combination of electronic components integrated together following the <span class="special2">IEEE</span> technology standards to aid in simplification of
                          the various current agricultural practices with the main purpose of improving <span class="special-term">production efficiency</span> at minimal costs, <span class="special-term">quality</span> of the products, <span class="special-term">conservation</span> of the natural resources as well as
                          checking on the <span class="special-term">health</span> and <span class="special-term">safe life</span> of the farm workers.</p>
                    </div> <!-- end of text-container -->
                    <!-- <i class="ri-check-double-line" style="color: darkred;"></i>&nbsp; -->
                    <div class="sections-seperator">
                      <hr>
                        <span class="dot"></span>
                        <span class="dot"></span>
                        <span class="dot"></span>
                    </div>
                      <!-- seperator line -->
                </div> <!-- end of col -->
                <div class="col-lg-7">
                    <div class="image-container">
                        <img class="img-fluid" src="main/images/bckgnd_dir/iot4.jpg" alt="alternative">
                    </div> <!-- end of image-container -->
                </div> <!-- end of col -->
            </div> <!-- end of row -->
        </div> <!-- end of container -->
    </div> <!-- end of basic-1 -->
    <!-- end of intro -->

    <!-- Services -->
    <div id="services" class="cards-2" style="background: #153e52;">
        <div class="container">
            <div class="row">
                <div class="col-lg-12">
                    <div class="section-title">HOW IT WORKS</div>
                  <p>
                    The project operates based on the control of some parameters determined by the integrated sensors
                    which are used as the monitoring elements for the system. These parameters include <span class="special-term">soil moisture levels</span>, <span class="special-term">temperature conditions</span>,
                    <span class="special-term">storage tank water levels</span>, <span class="special-term">power supply variables</span> among others.<br>
                    <br>
                  </p>
                </div> <!-- end of col -->
            </div> <!-- end of row -->
            <div class="row how-to-section">
                <div class="col-lg-12">
                    <!-- Card -->
                    <div class="card">
                      <div class="slide_sctn">
                        <div class="slider">
                          <figure>
                            <a target="_blank" href="main/images/bckgnd_dir/water_level_control_FC.png">
                              <img src="main/images/bckgnd_dir/water_level_control_FC.png" alt="loading image" title="water level control">
                            </a>
                            <a target="_blank" href="main/images/bckgnd_dir/irrigation control FC.png">
                              <img src="main/images/bckgnd_dir/irrigation control FC.png" alt="loading image" title="irrigation control">
                            </a>
                            <a target="_blank" href="main/images/bckgnd_dir/power supply control FC.png">
                              <img src="main/images/bckgnd_dir/power supply control FC.png" alt="loading image" title="power supply control">
                            </a>
                            <a target="_blank" href="main/images/bckgnd_dir/AAFC_Design.png">
                              <img src="main/images/bckgnd_dir/AAFC_Design.png"  alt="loading image" title="system design">
                            </a>
                            <a target="_blank" href="main/images/bckgnd_dir/water_level_control_FC.png">
                              <img src="main/images/bckgnd_dir/water_level_control_FC.png" alt="loading image" title="water level control">
                            </a>
                            <!-- <img src="images/bckgnd_dir/iot_wireless.png"  alt="loading image" title="system communication"> -->
                          </figure>
                        </div>
                      </div><br>
                        <h4 class="howto_no" style="font-weight: bolder;"><i class="ri-check-double-line" style="color: red;"></i>&nbsp;About AAFCS&nbsp;</h4>
                        <div class="media-body"><p>The project constitutes of a number of modules integrated together to form a complete independent functioning system ...</p></div><br>
                        <a class=" btn btn-link btn-solid-lg page-scroll" href="home.php">More</a>
                    </div>
                    <!-- end of card -->

                    <!-- Card -->
                    <div class="card">
                      <div class="slide_sctn">
                        <div class="slider">
                          <figure>
                            <img src="main/images/bckgnd_dir/img4_1.jpg" alt="">
                            <img src="main/images/bckgnd_dir/iot2.jpg" alt="">
                            <img src="main/images/bckgnd_dir/smart_system.jpg" alt="">
                            <img src="main/images/bckgnd_dir/solar_systm.png" alt="">
                            <img src="main/images/bckgnd_dir/img4_1.jpg" alt="">
                          </figure>
                        </div>
                      </div><br>
                        <h4 class="howto_no" style="font-weight: bolder;"><i class="ri-check-double-line" style="color: red;"></i>&nbsp;Operation&nbsp;</h4>
                        <div class="media-body"><p><span class="special2">AAFCS</span> system operation is based on close monitoring of the various farm parameters which are not limited to soil moisture, temperature, reserve tank water level ...</p></div><br>
                        <a class=" btn btn-link btn-solid-lg page-scroll" href="operation.php">More</a>
                    </div>
                    <!-- end of card -->

                    <!-- Card -->
                    <div class="card">
                      <div class="img_container">
                        <img class="img-fluid" src="main/images/bckgnd_dir/iot_wireless.png" alt="alternative">
                      </div><br>
                        <h4 class="howto_no" style="font-weight: bolder;"><i class="ri-check-double-line" style="color: red;"></i>&nbsp;Communication&nbsp;</h4>
                        <div class="media-body"><p>Information propagation is categorized into <span class="special-term">on-farm</span> and <span class="special-term">off-farm</span> communication. The on-farm method uses display units (LCDs) to pass information about the ongoing processes ...</p></div><br>
                        <a class=" btn btn-link btn-solid-lg page-scroll" href="operation.php">More</a>
                    </div>
                    <!-- end of card -->

                </div> <!-- end of col -->
            </div> <!-- end of row -->
        </div> <!-- end of container -->
    </div> <!-- end of cards-2 -->
    <!-- end of services -->

    <div class="row">
        <div class="text-container" style="padding: 4% 5% .2%;">
            <div class="section-title" style="text-align: center;">Data Processing</div>
            <div class="info-section"style="padding: 2% 1%;">
              <p>
                Information and data processing is handled partially at farm level and at the cloud servers.
                The latter plays fundamental role in advanced data analysis and manipulation. Storage is solely dedicated to end sever using
                SQL databases that provides easy querying and information storage and retrieval. This includes:
                <div class="list-elements"  style="margin-left: 4%">
                  <span class="special">></span> Soil moisture status<br>
                  <span class="special">></span> Soil Temperature status<br>
                  <span class="special">></span> Water consumption information<br>
                  <span class="special">></span> Water flowrate information<br>
                </div> <br>
              </p>
            </div>
        </div> <!-- end of text-container -->
        <div class="sections-seperator">
          <hr>
            <span class="dot"></span>
            <span class="dot"></span>
            <span class="dot"></span>
        </div>
          <!-- seperator line -->
    </div> <!-- end of row -->
    <!-- Footer -->
    <?php  include "main/footer.php"; ?>

    <!-- Scripts -->
    <script src="main/js/jquery.min.js"></script> <!-- jQuery for Bootstrap's JavaScript plugins -->
    <script src="main/js/popper.min.js"></script> <!-- Popper tooltip library for Bootstrap -->
    <script src="main/js/bootstrap.min.js"></script> <!-- Bootstrap framework -->
    <script src="main/js/jquery.easing.min.js"></script> <!-- jQuery Easing for smooth scrolling between anchors -->
    <script src="main/js/swiper.min.js"></script> <!-- Swiper for image and text sliders -->
    <script src="main/js/jquery.magnific-popup.js"></script> <!-- Magnific Popup for lightboxes -->
    <script src="main/js/morphext.min.js"></script> <!-- Morphtext rotating text in the header -->
    <script src="main/js/isotope.pkgd.min.js"></script> <!-- Isotope for filter -->
    <script src="main/js/validator.min.js"></script> <!-- Validator.js - Bootstrap plugin that validates forms -->
    <script src="main/js/scripts.js"></script> <!-- Custom scripts -->
</body>
</html>

<?php
/*

%%=============================================================
%%				              
%%	Author: ochieno eliud	                          
%%	University of Nairobi			  
%%	Dept: Elec. $ Info. Eng.		  
%%					  
%%==============================================================

*/
    session_start();
        // tracks user session
    include 'includes/header.php';
        // extends header file
?>
    <header>
      <style type="text/css">
        li a.home-active{
            color: red !important;
            background-color: #064c67;
        }
        a.side-bar-item1{
          background-color: #ddd !important;
          text-decoration: underline 1px solid #222;
          color: #405580;
        }
      </style>
    </header>
            <div class="section-ttl">
              <h2 class="h-title">Introduction</h2>
            </div>
            <div class="container intro-section">
                <h3 class="mt-4 sb-title">Research Problem</h3>
                <p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In Kenya, <span class="special-terms">Communications Authority (CAK)</span> regulates the telecommunocations sector through Licensing of
                    businesses in the communications sector. Licensing includes frequency spectrum management <span class="special-terms">(FSM)</span>, equipment
                    type approval <span class="special-terms">(TA)</span> and continuous monitoring of Quality of Service <span class="special-terms">(QoS)</span> and competition. However, it is beyond
                    the scope of the CA to monitor RF radiation levels in the community, especially those from numerous hand-held
                    devices.<br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;It is therefore imperative to perform measurement of radiation activity to ascertain if the levels are within ’healthy’
                    bands as approved by <span class="special-terms">World Health Organization (WHO)</span> and <span class="special-terms">International Telecommunications Union (ITU)</span> e.g.
                    at maximum, SAR := 2[W/kg]. This project will involve measurements of electric field intensity, E(V /m) from
                    several center frequencies used in the communications industry.<br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Furthermore, the effect of power levels on certain human body parts will be studied. In this regard, exposure to
                    hand-held devices will be evaluated through the evaluation of proximity of use to the body. These effects are best
                    studied through evaluation of specific absorption rate, SAR.<br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Firstly, a well-known theoretical model of SAR will be used to introduce the topic to trainees.
                    The depth to which radio waves penetrate exposed tissues depends on the frequency of the source, and the
                    electrical properties of the tissue. The depth of penetration (skin depth, δ) is given as:<br>
                    <br><img class="img-formula" src="static/imgs/formulas/skin-d.png">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="eqns-label">...[1.0]</span>
                        <!-- skin-depth formula -->
                    <br><br>where<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>&fnof;</i></span>:&nbsp;&nbsp;frequency of the source [Hz]
                          <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>&mu;</i></span>:&nbsp;&nbsp;magnetic permeability of tissue [H/m]
                          <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>&sigma;</i></span>:&nbsp;&nbsp;conductivity of the medium [S/m]
                    <br><br>
                    <h3 class="sb-content-title">Factors to Consider</h3>
                    <ul class="content-list">
                      <li><b>1.</b> Density of RF antennas: Urban, Rural, Metropolis, Educational centres</li>
                      <li><b>2.</b> Frequency of use: 2G, 3G, 4G, 5G + , Wi-Fi, IoT at different 3GPP power classes [1-5]</li>
                    </ul><br>
                    SAR is defined from electric field intensity, E as:<br><br>
                    <img class="img-formula" src="static/imgs/formulas/SAR1.png">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="eqns-label">...[1.1]</span>
                          <!-- SAR formula -->
                    <br><br>where<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>W</i></span>:&nbsp;&nbsp;absorbed energy [J]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>m</i></span>:&nbsp;&nbsp;tissue mass [Kg]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>&rho;</i></span>:&nbsp;&nbsp;tissue density [Kg/m^3]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>V</i></span>:&nbsp;&nbsp;potential difference [V]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>R</i></span>:&nbsp;&nbsp;resistance[&Omega;]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>&sigma;</i></span>:&nbsp;&nbsp;Conductivity [S/m]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>A</i></span>:&nbsp;&nbsp;surface area [m^2]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>E</i></span>:&nbsp;&nbsp;electric field intensity [V/m]
                    <br><br>The tissue power density is written as:<br><br>
                    <img class="img-formula" src="static/imgs/formulas/pwr-d.png">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="eqns-label">...[1.2]</span>
                        <!-- transmitted power -->
                    <br><br>and the intrinsic tissue impedance η is given as:<br><br>
                    <img class="img-formula" src="static/imgs/formulas/tissue-imp.png">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="eqns-label">...[1.3]</span>
                        <!-- ttissue impedance -->
                    <br><br>where<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>P<sub>t</sub></i></span>:&nbsp;&nbsp;transmitted power
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>G<sub>t</sub></i></span>:&nbsp;&nbsp;gain at the transmitter
                    <br><br><span><i>d</i></span> is the distance from the antenna to the tissue including depth of penetration: i.e.<br>
                    <br>&nbsp;&nbsp;<span><i>d = (d<sub>a</sub> + &delta;)</i>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;with d<sub>a</sub> as distance in air</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="eqns-label">...[1.4]</span>
                    <br><br>It is evident from <b>[1.1]</b> and <b>[1.2]</b> that if the tissue properties (&mu;<sub>r</sub>, &epsilon;<sub>r</sub>, &sigma;, &rho;) are known, the SAR can be computed
                    for any center frequency.<br><br>
                    <br><br>
                    <!-- <embed src="static/Techncl_pprs/Group_2_Conference_Paper.pdf" type="application/pdf" width="100%" height="600px" /> -->
                  </p>
            </div>
          </div>
        </div>
      <!-- /#page-content-wrapper -->
    </div>
          <!-- ------navbar script handler------ -->
        <script>
          $("#menu-toggle").click(function(e) {
            e.preventDefault();
            $("#wrapper").toggleClass("toggled");
          });
        </script>
    <!-- /#wrapper -->
    <!-- footer -->
    <?php
      include 'includes/footer.php';
    ?>
          <!-- extends footer section -->
  </body>
</html>

<?php
    session_start();
        // tracks user session
    include 'includes/header.php';
        // extends header file
?>
	<header>
    <link rel="stylesheet" type="text/css" href="includes/style.css">
		<link rel="stylesheet" type="text/css" href="static/css/simple-sidebar.css">
		<script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.3/Chart.min.js" type="text/javascript"></script>
		<link rel="stylesheet" type="text/css" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
    <!-- <linkrel="stylesheet" type="text/css"  href="//cdn.jsdelivr.net/gh/loadingio/ldbutton@v1.0.1/dist/ldbtn.min.css"/> -->
    <!-- <link rel="stylesheet" type="text/css" href='path/to/your/ldbtn.min.css' /> -->
    <style type="text/css">
      a.calc_tools-active{
        background-color: #ddd !important;
        text-decoration: underline 1px solid #222;
        color: #405580;
      }
        .btn{
          color: #fff !important;
        }
        form{
          background-color: #eeeeee !important;
          border: none;
          border-top: 2px solid #ccc;
        }
        h4{
          text-align: center;
        }
        span.key-terms{
          font-weight: lighter;
          color: blue !important;
        }
        span.term-definition{
          font-weight: lighter;
          color: #666 !important;
        }
        span#term-definition1,
        span#term-definition2,
        span#term-definition3,
        span#term-definition4,
        li#sctn1_hide,
        li#sctn2_hide,
        li#sctn3_hide,
        li#sctn4_hide{
          display: none;
        }
        ul.definitions{
          margin:  2% auto;
          padding: 1% 6%;
        }
        ul.definitions li{
          list-style: square !important;
          color: blue !important;
        }
        ul.definitions li:hover{
          text-decoration: underline;
          cursor: pointer;
        }
        b.dfn-identifier{
          color: blue;
        }
        .header-info-holder{
          width: 100%;
          padding: 2% 4%;
          overflow: hidden;
          background:linear-gradient(rgba(0, 0, 50, 0.5), rgba(0, 0, 50, 0.6)), url("static/imgs/RF_effects/RF-effect3.gif") !important;
          background-repeat: no-repeat !important;
          background-size: cover !important;
          background-position: center !important;
          color: #fff !important;
        }
        h4{
          font-weight: normal !important;
        }
        h2{
          font-weight: bold !important;
        }
		</style>
	</header>
    			<div class="section-ttl">
    				<h2 class="h-title">RF Calculators</h2>
          </div>
    			<div class="container">
            <div class="calc-tools-links">
              <ul>
                <li><a href="#skin_ddepth">Skin depth calculator</a></li>
                <li><a href="#fspl">Free Space Path Loss[FSPL] Calculator</a></li>
                <li><a href="#sar">Tissue Thickness Calculator</a></li>
                <li><a href="#dielec_properties">Dielectric Properties Calculator</a></li>
                <li><a href="#sar">SAR Calculator</a></li>
                <!-- <li><a href="#sar">SAR Calculator Advanced</a></li> -->
              </ul>
            </div>
            <div class="content-tools">
                    <!-- --------------SKIN dEPTH--------------- -->
              <div class="skin-depth">
                <div class="dfn-section">
                  <h4 class="dfn-ttl"><span class="special-terms">Skin Depth</span> </h4>
                  <a name="skin_ddepth"></a>
                  <p><span class="special-term"><i>Skin depth</i></span> is dependent on the frequency of the current/signal and the resistivity of the material. It inversely proportional to the
                     frequency and directly proportional to the resistivity.<br>Normally denoted as <span class="special-term">&delta;</span> and defined in units of meters[m], skin depth
                     is given by the equation:<br><br>
                     <img class="img-formula" src="static/imgs/formulas/skin_deoth11.png">&nbsp;&nbsp;&nbsp;[m]
                         <!-- skin depth formula -->
                     <br>With respect to conductivity as an inverse of resistivity, <span class="special-term"><i>skin depth</i></span> can be determined as:<br>
                     <br><img class="img-formula" src="static/imgs/formulas/skin-d.png">&nbsp;&nbsp;&nbsp;[m]<br>
                         <!-- skin-depth formula -->
                     <br><br>where:<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>&fnof;</i></span>:&nbsp;&nbsp;frequency of the source [Hz]
                           <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>&mu;</i></span>:&nbsp;&nbsp;magnetic permeability of material [H/m]
                           <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>&sigma;</i></span>:&nbsp;&nbsp;conductivity of the medium [S/m]
                           <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>&rho;</i></span>:&nbsp;&nbsp;resistivity of the medium [&Omega;.m]
                     <br><br>
                     <br>It is a measure of the current density, and is defined as the distances from the outer edges of a conductor to the point at which the current density falls to 1/e of the value at the surface
                  </p>
                </div>
                <div class="calc-tool-section">
                  <form class="calc-tool-section" id="skin_dpth_form">
                    <br><p style="color: #405580;">Calculate material skin depth<br><br>
                      <label class="rf-lalbels"><span class="special-term-abbriv">Enter:</span></label><br><br>
                      <label class="rf-lalbels">Frequency[<span class="special-term-abbriv">f</span>]</label><br>
                      <input class="fr-inputs skin_dpth_freq_choice_val" id="skin_dpth_freq_input_val" type="double" name="skin_dpth_freq_value" placeholder="value" required>
                      <select name="skin_dpth_freq_option" id="skin_dpth_freq_property" class="skin_dpth_property">
                        <option class="input100" value=""></option>
                        <span class="focus-input100"></span>
                        <option class="label-input100" type="text" value="mhz" selected>MHz</option>
                        <option class="label-input100" type="text" value="ghz">GHz</option>
                      </select><br><br>
                      <label class="rf-lalbels">Conductivity/Resistivity[<span class="special-term-abbriv">&sigma;/&rho;</span>]</label><br>
                      <input class="fr-inputs skin_dpth_property_choice_val"  id="skin_dpth_cond_restvty_optn_val" type="double" name="skin_dpth_property_value" placeholder="value" required>
                      <select name="skin_dpth_cndvty_rsstvty_option" id="skin_dpth_property" class="skin_dpth_property">
                        <option class="input100" value=""></option>
                        <span class="focus-input100"></span>
                        <option class="label-input100" type="text" value="conductivity" selected>Conductivity</option>
                        <option class="label-input100" type="text" value="resistivity">Resistivity</option>
                      </select><br><br>
                      <label class="rf-lalbels">Relative permeability[<span class="special-term-abbriv">&mu;r</span>]</label><br>
                      <input class="fr-inputs sar_rel_permeability_val" id="sar_rel_permeability_val" type="double" name="sar_rel_permeability" title="By default its set to unity" required><br><br><br>
                      <button class="btn calculate-btn" type="button" onclick="compute_skin_dpth();" name="calculate_skin_dpth_button">Calculate</button>
                      <button class="btn reset-btn" onclick="skin_dpth_fields_reset()" type="button" name="reset_skin_dpth_button" title="clear all inputs">Reset</button><br><br><br>
                      <label class="rf-lalbels">Skin Depth Result</label><br>
                      <input class="fr-inputs result_input_field"  id="skin_dpth_result_val" type="double" name="skin_depth_result_field">&nbsp;[m]<br>
                    </p>
                  </form>
                </div>
              </div>
              <div class="sections-seperator">
                <hr>
                  <span class="dot"></span>
                  <span class="dot"></span>
                  <span class="dot"></span>
                <!-- seperator line -->
              </div>
                    <!-- --------------FSPL--------------- -->
              <div class="fspl">
                <a name="fspl"></a>
                <div class="dfn-section">
                  <h4 class="dfn-ttl"><span class="special-terms">Free Space Path Loss [FSPL] Calculator</span> </h4>
                  <p><span class="special-term-abbriv"><i>FSPL</i></span> is the loss in signal strength as it travels through free space. This value is usually calculated by discounting
                     any obstacles or reflections that might occur in its path. <span class="special-term-abbriv">IEEE</span> defines it as <span class="special-term"><i>The loss between two isotropic radiators in free space, expressed as a power ratio</i></span>.
                     <br>It is expressed in dB.<br><br>
                     <div class="formula-section">
                         <span class="special-term-abbriv">FSPL = 20log<sub>10</sub>(d) + 20log<sub>10</sub>(f) + 20log<sub>10</sub>((4&pi;)/c) - G<sub>TX</sub> - G<sub>TR</sub></span>&nbsp;&nbsp;&nbsp;[dB]<br>
                             <!-- fspl formula -->
                     </div>
                   <br><br>where<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>d</i></span>:&nbsp;&nbsp;Distance between the antennas [m]
                   <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>f</i></span>:&nbsp;&nbsp;operating frequency [Hz]
                   <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>G<sub>TX</sub></i></span>:&nbsp;&nbsp;Gain of transmitting antenna [dB]
                   <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>G<sub>TR</sub></i></span>:&nbsp;&nbsp;Gain of receiving antenna [dB]
                   <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>c</i></span>:&nbsp;&nbsp;Speed of light in vacuum[m/s]
                   <br>The <span class="special-term">free space path loss</span> is used to predict the strength of a <span class="special-term-abbriv">RF</span> signal at a particular distance. This is a theoretical
                    value, as in the real world, there are many obstacles, reflections and losses which need to be accounted for when
                    estimating the signal at a location. However the <span class="special-term-abbriv">FSPL</span> is a good approximation for estimating
                    the loss of signal when propagating through free space.
                  </p>
                </div>
                <div class="calc-tool-section">
                  <form class="calc-tool-section" id="fspl_form">
                  <br><p style="color: #405580;">Calculate signal strength loss in free space.<br><br>
                      <label class="rf-lalbels"><span class="special-term-abbriv">Enter:</span></label><br><br>
                      <label class="rf-lalbels">Distance[<span class="special-term-abbriv">d</span>]</label><br>
                      <input class="fr-inputs fspl_dist_choice_val" id="fspl_dist_input_val" type="double" name="fspl_value" placeholder="value" required>
                      <select name="fspl_distance_range_option" id="fspl_dist_property" class="fspl_prooperty">
                        <option class="input100" value=""></option>
                        <span class="focus-input100"></span>
                        <option class="label-input100" type="text" value="km" selected>km</option>
                        <option class="label-input100" type="text" value="m">metres</option>
                      </select><br><br>
                      <label class="rf-lalbels">Frequency[<span class="special-term-abbriv">f</span>]</label><br>
                      <input class="fr-inputs fspl_freq_choice_val" id="fspl_freq_input_val" type="double" name="fspl_value" placeholder="value" required>
                      <select name="fspl_freq_range_option" id="fspl_freq_property" class="fspl_operty">
                        <option class="input100" value=""></option>
                        <span class="focus-input100"></span>
                        <option class="label-input100" type="text" value="mhz" selected>MHz</option>
                        <option class="label-input100" type="text" value="ghz">GHz</option>
                      </select><br><br>
                      <label class="rf-lalbels">Transmitting antenna gain[<span class="special-term-abbriv">G<sub>TX</sub></span>]</label><br>
                      <input class="fr-inputs fspl_gain_input_val" id="fspl_tx_gai_input_val" type="double" name="fspl_tx_gain" title="By default its set to unity" required><br><br>
                      <label class="rf-lalbels">Receiving antenna gain[<span class="special-term-abbriv">G<sub>RX</sub></span>]</label><br>
                      <input class="fr-inputs fspl_gain_input_val" id="fspl_rx_gain_input_val" type="double" name="fspl_rx_gain" title="By default its set to unity" required><br><br><br>
                      <button class="btn calculate-btn" type="button" onclick="compute_fspl();" name="calculate_fspl_button">Calculate</button>
                      <button class="btn reset-btn" onclick="fspl_fields_reset();" type="button" name="reset_fspl_button" title="clear all inputs">Reset</button><br><br><br>
                      <label class="rf-lalbels">FSPL Result</label><br>
                      <input class="fr-inputs result_input_field" id="fspl_result_val" type="double" name="fspl_result_field">&nbsp;[dB]<br>
                    </p>
                  </form>
                </div>
              </div>
              <div class="sections-seperator">
                <hr>
                  <span class="dot"></span>
                  <span class="dot"></span>
                  <span class="dot"></span>
                <!-- seperator line -->
              </div>
                    <!-- --------------TISSUE THICKNESS--------------- -->
              <div class="head_model">
                <div class="dfn-section">
                  <h4 class="dfn-ttl"><span class="special-terms">Human Head-RF Source Modeling</span> </h4>
                  <a name="head_model"></a>
                  <p><span class="special-term"><i></i></span>In order to assess human exposure to mobile phone electromagnetic fields, it is required to
                     construct an appropriate model of a human head and the RF source (phone).<br>Considering a human head modeled as a four-layer structure that consist of
                     <span class="special-term"><i> skin, fat, skull </i></span>and <span class="special-term"><i>brain</i></span>.<br>The human head biological tissues may be considered as lossy dielectric materials with
                     permeability equal to free space permeability(<span class="special-term">&mu;=&mu;<sub>o</sub></span>),and conductivity that depends on tissue
                     properties and signal frequency.<br>For instance consider a mobile phone assumed to be in transmit
                     mode, that transmits RF energy in a single direction towards the head as it is assumed to be
                     located 2 cm away from the human head. The human head model is as shown:<br><br>
                     <div class="">
             		          <a target="_blank" href="static/imgs/formulas/Human Head Model.png">
                          <img class="img-formula" style="width:90%; overflow:hidden; margin-right: 2%;" src="static/imgs/formulas/Human Head Model.png" title="view"></a>
                     </div>
                     <span class="special-term reference_title">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>Fig1: </b><i>RF Source-Human Head Model</i><br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>Reference:</b>Godra, L. Chand, Handbook</span>
                         <!-- model figure-->
                  </p>
                </div>
                <div class="calc-tool-section">
                  <form class="calc-tool-section" id="head_siz_model_form">
                    <br><p style="color: #405580;">Calculate tissue thickness<br><br>
                      <label class="rf-lalbels"><span class="special-term-abbriv">Enter:</span></label><br><br>
                      <label class="rf-lalbels">Head size[<span class="special-term-abbriv">m</span>]</label><br>
                      <input class="fr-inputs head_siz_model_choice_val" id="head_siz_model_input_val" type="double" name="head_siz_model_value" placeholder="value" required>
                      <select name="head_siz_model_option" id="head_siz_model_property" class="head_siz_model_property">
                        <option class="input100" value=""></option>
                        <span class="focus-input100"></span>
                        <option class="label-input100" type="text" value="radius" selected>Radius</option>
                        <option class="label-input100" type="text" value="circumference">Circumference</option>
                      </select><br><br><br>
                      <button class="btn calculate-btn" type="button" onclick="head_model_compute();" name="calculate_head_siz_model_button">Calculate</button>
                      <button class="btn reset-btn" onclick="head_model_fields_reset()" type="button" name="head_siz_model_reset_button" title="clear all inputs">Reset</button><br><br><br>
                      <label class="rf-lalbels">Tissue thickness result</label><br>
                      <label class="rf-lalbels" style="margin-right:2%;">Skin:&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field" id="head_siz_model_skin_thcknss_result_val" type="double" name="head_siz_model_result_field">&nbsp;[m]<br>
                      <label class="rf-lalbels" style="margin-right:2%;">Fat:&nbsp;&nbsp;&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field" id="head_siz_model_fat_thcknss_result_val" type="double" name="head_siz_model_result_field">&nbsp;[m]<br>
                      <label class="rf-lalbels" style="margin-right:1%;">Bone:&nbsp;</label>
                      <input class="fr-inputs result_input_field" id="head_siz_model_bone_thcknss_result_val" type="double" name="head_siz_model_result_field">&nbsp;[m]<br>
                      <label class="rf-lalbels" style="margin-right:2%;">Brain:</label>
                      <input class="fr-inputs result_input_field" id="head_siz_model_brain_thcknss_result_val" type="double" name="head_siz_model_result_field">&nbsp;[m]<br>
                    </p>
                  </form>
                </div>
              </div>
              <div class="sections-seperator">
                <hr>
                  <span class="dot"></span>
                  <span class="dot"></span>
                  <span class="dot"></span>
                <!-- seperator line -->
              </div>

                    <!-- --------------TISSUE DIELECTRIC PROPERTIES--------------- -->
              <div class="dielectric_properties" style="display: block;">
                <div class="dfn-section">
                  <h4 class="dfn-ttl"><span class="special-terms">Body Tissues Dielectric Properties</span> </h4>
                  <a name="dielec_properties"></a>
                  <p>A <span class="special-term">dielectric</span> (or <span class="special-term">dielectric material</span>) is an <span class="key-terms"><a href="#e-insulator">electrical insulator</a></span> that can be polarized by an applied <span class="key-terms"><a href="#e-field">electric field</a></span>. When a dielectric material is placed in an electric field, electric
                    charges do not flow through the material as they do in an <span class="key-terms"><a href="#e-conductor">electrical conductor</a></span> but only slightly shift from their average equilibrium positions
                    causing dielectric <span class="key-terms"><a href="#polarization">polarization</a></span>.<br>Because of dielectric <span class="special-term">polarization</span>, positive charges are displaced in the direction of the field and negative charges shift in the direction opposite to the field (for example, if the field is moving in the positive
                    x-axis, the negative charges will shift in the negative x-axis). This creates an internal electric field that reduces the overall field within the dielectric itself.
                    If a dielectric is composed of weakly bonded molecules, those molecules not only become polarized, but also reorient so that their symmetry axes align to the field.<br>The study of dielectric properties concerns storage and dissipation of electric and magnetic energy in materials.
                    Dielectrics are important for explaining various phenomena in electronics, optics, solid-state physics, and cell biophysics. <br><br>
                    <span class="special-terms"><u>Definitions</u></span>
                    <ul class="definitions">
                      <li onclick="toggle_term_definition1();" id="sctn1_show"><a name="e-insulator"></a>electrical insulator</li>
                      <li onclick="toggle_term_frm_display_definition1();" id="sctn1_hide"><a name="e-insulator"></a>electrical insulator</li>
                      <span class="term-definition" id="term-definition1">
                      <b class="dfn-identifier">></b>  An <span class="special-term">electrical insulator</span> is a material in which the electron does not flow freely or the atom of the insulator have tightly bound electrons whose internal electric charges do not flow freely; very little electric current will flow through it under the influence of an electric field.
                      </span>
                      <li onclick="toggle_term_definition2();" id="sctn2_show"><a name="e-field"></a>electric field</li>
                      <li onclick="toggle_term_frm_display_definition2();" id="sctn2_hide"><a name="e-field"></a>electric field</li>
                      <span class="term-definition" id="term-definition2">
                        <b class="dfn-identifier" >></b> An <span class="special-term">electric field</span> (also termed as <span class="special-term">E-field</span>) is the physical field that surrounds each electric charge and exerts force on all other charges in the field, either attracting or repelling them. It originate from electric charges, or from time-varying magnetic fields.
                      </span>
                      <li onclick="toggle_term_definition3();" id="sctn3_show"><a name="e-conductor"></a>electrical conductor</li>
                      <li onclick="toggle_term_frm_display_definition3();" id="sctn3_hide"><a name="e-conductor"></a>electrical conductor</li>
                      <span class="term-definition" id="term-definition3">
                        <b class="dfn-identifier" >></b> A <span class="special-term">conductor</span> is an object or type of material that allows the flow of charge (electrical current) in one or more directions. Materials made of metal are common electrical conductors. <span class="special-term">Electrical current</span> is generated by the flow of negatively charged electrons, positively charged holes, and positive or negative ions in some cases.
                      </span>
                      <li onclick="toggle_term_definition4();" id="sctn4_show"><a name="polarization"></a>polarization</li>
                      <li onclick="toggle_term_frm_display_definition4();" id="sctn4_hide"><a name="polarization"></a>polarization</li>
                      <span class="term-definition" id="term-definition4">
                        <b class="dfn-identifier" >></b> <span class="special-term">Polarization density</span> (or <span class="special-term">electric polarization</span>, or simply <span class="special-term">polarization</span>) is the vector field that expresses the density of permanent or induced electric <span class="special-term">dipole moments</span> in a dielectric material. When a dielectric is placed in an external electric field, its molecules gain electric dipole moment and the dielectric is said to be polarized.
                        The electric dipole moment induced per unit volume of the dielectric material is called the electric polarization of the dielectric
                      </span>
                    </ul>
                    <br><b>Where:</b>
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>&sigma;</i></span>:&nbsp;&nbsp;tissue conductivity [S/m]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>m<sub>d</sub></i></span>:&nbsp;&nbsp;tissue mass density [Kg/m<sup>3</sup>]
                    <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="special-term-abbriv"><i>&epsilon;<sub>r</sub></i></span>:&nbsp;&nbsp;tissue relative permittivity.
                <br><br>
                     <br><br>
                    <div class="">
                         <a target="_blank" href="static/imgs/formulas/dielectric_properties.png">
                         <img class="img-formula" style="width:90%; overflow:hidden; margin-right: 2%;" src="static/imgs/formulas/dielectric_properties.png" title="view"></a>
                    </div>
                    <span class="special-term reference_title">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>Fig2: </b><i>A polarized dielectric material</i><br></span>
                    <!-- <span class="special-term reference_title">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>Fig2: </b><i>A polarized dielectric material</i><br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>Reference:</b> <a href="https://byjus.com/physics/dielectric-properties/"> <span class="key-terms">Dielectric properties definition</span> </a> </span> -->
                        <!-- model figure-->
                  </p>
                </div>
                <div class="calc-tool-section">
                  <form class="calc-tool-section" id="dielectric_properties_form">
                    <br><p style="color: #405580;">Determine Tissues Dielectric Properties<br><br>
                      <label class="rf-lalbels"><span class="special-term-abbriv">Enter:</span></label><br><br>
                      <label class="rf-lalbels">Frequency range</label><br>
                      <input class="fr-inputs dielectric_properties_choice_val" id="dielectric_properties_ferq_input_val" type="double" name="dielectric_properties_freq_value" placeholder="value" required>
                      <select name="dielectric_properties_freq_range_option" id="dielectric_properties_freq_range_optn" class="dielectric_properties_freq_range_optn">
                        <option class="input100" value=""></option>
                        <span class="focus-input100"></span>
                        <option class="label-input100" type="text" value="mhz" selected>MHz</option>
                        <option class="label-input100" type="text" value="ghz">GHz</option>
                      </select><br><br><br>
                      <button class="btn calculate-btn" type="button" onclick="dielectric_properties_fetch();" name="dielectric_properties_fetch_button">Determine</button>
                      <button class="btn reset-btn" onclick="dielectric_properties_reset()" type="button" name="dielectric_properties_reset_button" title="clear all inputs">Reset</button><br><br><br>
                      <label class="rf-lalbels">1. Skin tissue properties</label><br>
                      <label class="rf-lalbels" style="margin-right:2%;"><span class="special-term-abbriv"><i>&sigma;: </i></span>&nbsp;&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_skin_condctvty_val" type="double" name="dielec_prop_skin_condctvty_field">&nbsp;[S/m]<br>
                      <label class="rf-lalbels" style="margin-right:2%;"><span class="special-term-abbriv"><i>&epsilon;<sub>r</sub>: </i></span>&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_skin_rel_permitvtty_val" type="double" name="dielec_prop_skin_rel_permitvtty_field">&nbsp;<br>
                      <label class="rf-lalbels" style="margin-right:1%;"><span class="special-term-abbriv"><i>m<sub>d</sub>: </i></span>&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_skin_density_val" type="double" name="dielec_prop_skin_density_field" style="margin-right: 2">&nbsp;[Kg/m<sup>3</sup>]<br><br>

                      <label class="rf-lalbels">2. Fat tissue properties</label><br>
                      <label class="rf-lalbels" style="margin-right:2%;"><span class="special-term-abbriv"><i>&sigma;: </i></span>&nbsp;&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_fat_condctvty_val" type="double" name="dielec_prop_fat_condctvty_field">&nbsp;[S/m]<br>
                      <label class="rf-lalbels" style="margin-right:2%;"><span class="special-term-abbriv"><i>&epsilon;<sub>r</sub>: </i></span>&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_fat_rel_permitvtty_val" type="double" name="dielec_prop_fat_rel_permitvtty_field">&nbsp;<br>
                      <label class="rf-lalbels" style="margin-right:1%;"><span class="special-term-abbriv"><i>m<sub>d</sub>: </i></span>&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_fat_density_val" type="double" name="dielec_prop_fat_density_field" style="margin-right: 2">&nbsp;[Kg/m<sup>3</sup>]<br><br>

                      <label class="rf-lalbels">3. Bone tissue properties</label><br>
                      <label class="rf-lalbels" style="margin-right:2%;"><span class="special-term-abbriv"><i>&sigma;: </i></span>&nbsp;&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_bone_condctvty_val" type="double" name="dielec_prop_bone_condctvty_field">&nbsp;[S/m]<br>
                      <label class="rf-lalbels" style="margin-right:2%;"><span class="special-term-abbriv"><i>&epsilon;<sub>r</sub>: </i></span>&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_bone_rel_permitvtty_val" type="double" name="dielec_prop_bone_rel_permitvtty_field">&nbsp;<br>
                      <label class="rf-lalbels" style="margin-right:1%;"><span class="special-term-abbriv"><i>m<sub>d</sub>: </i></span>&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_bone_density_val" type="double" name="dielec_prop_bone_density_field" style="margin-right: 2">&nbsp;[Kg/m<sup>3</sup>]<br><br>

                      <label class="rf-lalbels">4. Brain tissue properties</label><br>
                      <label class="rf-lalbels" style="margin-right:2%;"><span class="special-term-abbriv"><i>&sigma;: </i></span>&nbsp;&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_brain_condctvty_val" type="double" name="dielec_prop_brain_condctvty_field">&nbsp;[S/m]<br>
                      <label class="rf-lalbels" style="margin-right:2%;"><span class="special-term-abbriv"><i>&epsilon;<sub>r</sub>: </i></span>&nbsp;&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_brain_rel_permitvtty_val" type="double" name="dielec_prop_brain_rel_permitvtty_field">&nbsp;<br>
                      <label class="rf-lalbels" style="margin-right:1%;"><span class="special-term-abbriv"><i>m<sub>d</sub>: </i></span>&nbsp;</label>
                      <input class="fr-inputs result_input_field result_input_field_dielec_prop" id="dielec_prop_brain_density_val" type="double" name="dielec_prop_brain_density_field" style="margin-right: 2">&nbsp;[Kg/m<sup>3</sup>]<br>
                    </p>
                  </form>
                </div>
              </div>
              <div class="sections-seperator">
                <hr>
                  <span class="dot"></span>
                  <span class="dot"></span>
                  <span class="dot"></span>
                <!-- seperator line -->
              </div>
                    <!-- --------------SAR--------------- -->
                <div class="sar" id="sar_basic_sctn">
                    <a name="sar"></a>
                    <div class="dfn-section">
                      <h4 class="dfn-ttl"><span class="special-terms">Specific Absorption Rate (SAR)</span> <br> (Basic calculator)</h4>
                      <p><span class="special-term"><i>SAR</i></span> is a unit of measurement for the amount of radio frequency energy absorbed by the body when using a wireless device.<br>
                        <br>It is determined as:<br>
                        <br><img class="img-formula" src="static/imgs/formulas/SAR2.png">&nbsp;&nbsp;&nbsp;[W/Kg]
                           <!-- skin-depth formula -->
                        <br><br>The tissue power density is defined as:<br><br>
                        <img class="img-formula" src="static/imgs/formulas/pwr-d.png">&nbsp;&nbsp;&nbsp;[W/m<sup>3</sup>]
                           <!-- transmitted power -->
                        <br><br>where<br>
                       <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>m<sub>d</sub></i></span>:&nbsp;&nbsp;tissue mass density [Kg/m<sup>3</sup>]
                       <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>&sigma;</i></span>:&nbsp;&nbsp;Conductivity [S/m]
                       <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i>E</i></span>:&nbsp;&nbsp;electric field intensity [V/m]
                      </p>
                    </div>
                    <div class="calc-tool-section">
                      <form class="calc-tool-section" id="sar_form">
                          <br><p style="color: #405580;">Calculate specific absorption rate for the material.<br><br>
                            <label class="rf-lalbels"><span class="special-term-abbriv">Enter:</span></label><br><br>
                            <label class="rf-lalbels">Electric field intensity[<span class="special-term-abbriv">E</span>]</label><br>
                            <input class="fr-inputs sar_field_input_val" id="sar_efield_input_val" type="double" name="sar_matrl_efield" placeholder="" required>&nbsp;[V/m]<br><br>
                            <label class="rf-lalbels">Conductivity of material[<span class="special-term-abbriv">&sigma;</span>]</label><br>
                            <input class="fr-inputs sar_field_input_val" id="sar_condctvty_input_val" type="double" name="sar_matrl_conductivity" placeholder="" required>&nbsp;[S/m]<br><br>
                            <label class="rf-lalbels">Material density[<span class="special-term-abbriv">m<sub>d</sub></span>]</label><br>
                            <input class="fr-inputs sar_field_input_val" id="sar_mat_dnsty_input_val" type="double" name="sar_matrl_density" placeholder="" required>&nbsp;[Kg/m<sup>3</sup>]<br><br><br>
                            <button class="btn calculate-btn" onclick="compute_sar();" type="button" name="calculate_sar_button">Calculate</button>
                            <button class="btn reset-btn" onclick="sar_fields_reset()" type="button" name="reset_sar_button" title="clear all inputs">Reset</button><br><br><br>
                            <label class="rf-lalbels">SAR Result</label><br>
                            <input class="fr-inputs result_input_field" id="sar_result_val" type="double" name="sar_result_field">&nbsp;[W/Kg]<br>
                          </p>
                      </form>
                    </div>
                  </div>
                <div class="sections-seperator" id="sar_basic_seperator_sctn">
                    <hr>
                      <span class="dot"></span>
                      <span class="dot"></span>
                      <span class="dot"></span>
                    <!-- seperator line -->
                      <button class="btn btn-dlt toggle_table" style="margin-left: 2%; float: right;" type="button" onclick="toggle_sar_advanced_calc()">Advanced</button>
                        <!-- toggle calc tool -->
                  </div><br>
                        <!-- --------------SAR-ADVANCED--------------- -->
                <div class="sar_advanced" id="sar_advanced_sctn" style="display:none;">
                  <a name="sar"></a>
                  <div class="dfn-section">
                    <h4 class="dfn-ttl"><span class="special-terms">Specific Absorption Rate (SAR)</span> <br> (Advanced calculator)</h4>
                    <p><span class="special-term"><i>SAR</i></span> is a unit of measurement for the amount of radio frequency energy absorbed by a body when using a wireless device.<br>
                      <br>It is determined as:<br>
                      <br><img class="img-formula" src="static/imgs/formulas/SAR2.png">&nbsp;&nbsp;&nbsp;[W/Kg]
                         <!-- skin-depth formula -->
                      <br><br>The tissue power density is defined as:<br><br>
                      <img class="img-formula" src="static/imgs/formulas/pwr-d.png">&nbsp;&nbsp;&nbsp;[W/m<sup>3</sup>]
                         <!-- transmitted power -->
                      <br><br>where
                     <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i><b>m<sub>b</sub></b></i></span>:&nbsp;&nbsp;tissue mass density [Kg/m<sup>3</sup>]
                     <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i><b>&sigma;</b></i></span>:&nbsp;&nbsp;Conductivity [S/m]
                     <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span><i><b>E</b></i></span>:&nbsp;&nbsp;electric field intensity [V/m]<br><br>
                     <span class="special-term"><b><u>Constants</u></b></span>
                     <br>&nbsp;&nbsp;&nbsp;<span><i><b>&epsilon;<sub>o</sub></b></i></span>&nbsp;&nbsp;= 8.854187 x 10<sup>-12</sup>[F/m]
                     <br>&nbsp;&nbsp;&nbsp;<span><i><b>&mu;<sub>o</sub></b></i></span>&nbsp;&nbsp;= 4&pi; x 10<sup>-7</sup>[H/m]
                     <br>&nbsp;&nbsp;&nbsp;<span><i><b>c<sub>o</sub></b></i></span>&nbsp;&nbsp;= 3 x 10<sup>8</sup>[m/s]
                     <br>&nbsp;&nbsp;&nbsp;<span><i><b>n<sub>o</sub></b></i></span>&nbsp;&nbsp;= 120&pi;[&Omega;]
                    </p>
                  </div>
                  <div class="calc-tool-section">
                    <form class="calc-tool-section" id="sar_advanced_form">
                        <br><p style="color: #405580;">Calculate specific absorption rate for the material.<br><br>
                          <label class="rf-lalbels"><span class="special-term-abbriv">Enter:</span></label><br><br>

                          <label class="rf-lalbels">Device distance[<span class="special-term-abbriv">d<sub>a</sub></span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_dvc_dist_input_val" type="double" name="fspl_value" placeholder="value" required>
                          <select name="sar_advncd_distance_range_option" id="sar_advncd_distance_range_option" class="fspl_prooperty">
                            <option class="input100" value=""></option>
                            <span class="focus-input100"></span>
                            <option class="label-input100" type="text" title="centimeters" value="cm" selected>cm</option>
                            <option class="label-input100" type="text" title="meters" value="m">m</option>
                            <option class="label-input100" type="text" title="kilometers" value="km">km</option>
                          </select><br><br>

                          <label class="rf-lalbels">Frequency[<span class="special-term-abbriv">f<sub>c</sub></span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_freq_input_val" type="double" name="fspl_value" placeholder="value" required>
                          <select name="sar_advncd_freq_range_option" id="sar_advncd_freq_range_optn" class="fspl_operty">
                            <option class="input100" value=""></option>
                            <span class="focus-input100"></span>
                            <option class="label-input100" type="text" value="mhz" selected>MHz</option>
                            <option class="label-input100" type="text" value="ghz">GHz</option>
                          </select><br><br>

                          <label class="rf-lalbels">Head size[<span class="special-term-abbriv">m</span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_head_siz_input_val" type="double" name="tissue_thickness_value" placeholder="value" required>
                          <select name="sar_advncd_head_siz_option" id="sar_advncd_head_siz_property" class="sar_advncd_head_siz_property">
                            <option class="input100" value=""></option>
                            <span class="focus-input100"></span>
                            <option class="label-input100" type="text" value="radius" selected>Radius</option>
                            <option class="label-input100" type="text" value="circumference">Circumference</option>
                          </select><br><br>

                          <label class="rf-lalbels" style="margin-right: 2%;">Tissue type:</label>
                          <select name="sar_advncd_tissue_type_option" id="sar_advncd_tissue_type_option" class="sar_advncd_tissue_type_option">
                            <option class="input100" value=""></option>
                            <span class="focus-input100"></span>
                            <option class="label-input100" type="text" value="Skin" selected>Skin</option>
                            <option class="label-input100" type="text" value="Fat">Fat</option>
                            <option class="label-input100" type="text" value="Bone">Bone</option>
                            <option class="label-input100" type="text" value="Brain">Brain</option>
                          </select><br><br>

                          <label class="rf-lalbels">Transmitted power[<span class="special-term-abbriv">P<sub>t</sub></span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_pwr_tr_val" type="double" name="sar_rel_permeability" placeholder="" required>&nbsp;[W]<br><br>

                          <label class="rf-lalbels">Antenna Gain[<span class="special-term-abbriv">G<sub>t</sub></span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_ant_gain_val" type="double" name="sar_rel_permeability" title="By default its set to unity" required><br><br>

                          <label class="rf-lalbels">Relative permeability[<span class="special-term-abbriv">&mu;<sub>r</sub></span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_rel_permeability_val" type="double" name="sar_rel_permeability" title="By default its set to unity" required><br><br>

                          <label class="rf-lalbels">Relative permittivity[<span class="special-term-abbriv">&epsilon;<sub>r</sub></span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_rel_permitivity_val" type="double" name="sar_rel_permeability" placeholder="" required><br><br>

                          <label class="rf-lalbels">Tissue conductivity[<span class="special-term-abbriv">&sigma;</span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_conductivity_val" type="double" name="sar_rel_permeability" placeholder="" required>&nbsp;[S/m]<br><br>

                          <label class="rf-lalbels">Tissue density[<span class="special-term-abbriv">&rho;</span>]</label><br>
                          <input class="fr-inputs sar_advanced_input_field" id="sar_advncd_tissue_dnsty_val" type="double" name="sar_rel_permeability" placeholder="" required>&nbsp;[Kg/m<sup>3</sup>]<br><br>

                          <button class="btn calculate-btn" onclick="sar_advanced_compute();" type="button" name="calculate_sar_advncd_button">Calculate</button>
                          <button class="btn reset-btn" onclick="sar_advanced_fields_reset()" type="button" name="reset_sar_advncd_button" title="clear all inputs">Reset</button><br><br><br>
                          <label class="rf-lalbels">Skin depth</label><br>
                          <input class="fr-inputs result_input_field" id="sar_advncd_skin_dpth_result_val" type="double" name="sar_advncd_result_field">&nbsp;[m]<br><br>
                          <label class="rf-lalbels">Impedance</label><br>
                          <input class="fr-inputs result_input_field" id="sar_advncd_impedance_result_val" type="double" name="sar_advncd_result_field">&nbsp;[&Omega;]<br><br>
                          <label class="rf-lalbels">Power density[<span class="special-term-abbriv">S</span>]</label><br>
                          <input class="fr-inputs result_input_field" id="sar_advncd_pwr_dnsty_result_val" type="double" name="sar_advncd_result_field">&nbsp;[W/m<sup>3</sup>]<br><br>
                          <label class="rf-lalbels">Electric field intensity[<span class="special-term-abbriv">E<sup>2</sup></span>]</label><br>
                          <input class="fr-inputs result_input_field" id="sar_advncd_e_field_result_val" type="double" name="sar_advncd_result_field">&nbsp;[V/m]<br><br>
                          <label class="rf-lalbels">SAR</label><br>
                          <input class="fr-inputs result_input_field" id="sar_advncd_result_val" type="double" name="sar_advncd_result_field">&nbsp;[W/Kg]<br>
                        </p>
                    </form>
                  </div>
                </div>
                <div class="sections-seperator" id="sar_advanced_seperator_sctn" style="display:none;">
                  <hr>
                    <span class="dot"></span>
                    <span class="dot"></span>
                    <span class="dot"></span>
                  <!-- seperator line -->
                    <button class="btn btn-dlt toggle_table" style="margin-left: 2%; float: right;" type="button" onclick="toggle_sar_basic_calc()">Basic</button>
                      <!-- toggle calc tool -->
                </div><br>
            </div>
                       <!-- ---------controls toggling handler--------- -->
            <script>
               function toggle_sar_advanced_calc(){
                 document.getElementById("sar_basic_sctn").style.display = "none";
                 document.getElementById("sar_advanced_sctn").style.display = "block";
                 document.getElementById("sar_basic_seperator_sctn").style.display = "none";
                 document.getElementById("sar_advanced_seperator_sctn").style.display = "block";
               }
               function toggle_sar_basic_calc(){
                 document.getElementById("sar_basic_sctn").style.display = "block";
                 document.getElementById("sar_advanced_sctn").style.display = "none";
                 document.getElementById("sar_basic_seperator_sctn").style.display = "block";
                 document.getElementById("sar_advanced_seperator_sctn").style.display = "none";
               }
               function toggle_term_definition1(){
                document.getElementById("term-definition1").style.display = "block";
                document.getElementById("sctn1_hide").style.display = "block";
                document.getElementById("sctn1_show").style.display = "none";
              }
              function toggle_term_frm_display_definition1(){
                document.getElementById("term-definition1").style.display = "none";
                document.getElementById("sctn1_hide").style.display = "none";
                document.getElementById("sctn1_show").style.display = "block";
              }
               function toggle_term_definition2(){
                document.getElementById("term-definition2").style.display = "block";
                document.getElementById("sctn2_hide").style.display = "block";
                document.getElementById("sctn2_show").style.display = "none";
              }
              function toggle_term_frm_display_definition2(){
                document.getElementById("term-definition2").style.display = "none";
                document.getElementById("sctn2_hide").style.display = "none";
                document.getElementById("sctn2_show").style.display = "block";
              }
               function toggle_term_definition3(){
                document.getElementById("term-definition3").style.display = "block";
                document.getElementById("sctn3_hide").style.display = "block";
                document.getElementById("sctn3_show").style.display = "none";
              }
              function toggle_term_frm_display_definition3(){
                document.getElementById("term-definition3").style.display = "none";
                document.getElementById("sctn3_hide").style.display = "none";
                document.getElementById("sctn3_show").style.display = "block";
              }
               function toggle_term_definition4(){
                document.getElementById("term-definition4").style.display = "block";
                document.getElementById("sctn4_hide").style.display = "block";
                document.getElementById("sctn4_show").style.display = "none";
              }
              function toggle_term_frm_display_definition4(){
                document.getElementById("term-definition4").style.display = "none";
                document.getElementById("sctn4_hide").style.display = "none";
                document.getElementById("sctn4_show").style.display = "block";
              }
            </script>
            <script>
              // --------------operations----------------
              var pi = Math.PI;
                      // pi value
              var eo = 8.854187*Math.pow(10, -12);
                      // Permittivity [F/m]
              var uo = 4*pi*Math.pow(10, -7);
                      // Permeability [H/m]
              var ur = document.getElementById('sar_rel_permeability_val').value;
                      // relative permeability
              if (ur <= 0) {
                  ur = 1;
              }
                      // sets relative permeability to 1 if not set
              var co = 3*Math.pow(10, 8);
                      // Speed of EM [m/s]
              var no = 120*pi;
                      // free space x-tic impedance
              var error_flag;
                  error_flag ='OFF';
                      // process track flag set LOW by default

              document.getElementById('skin_dpth_re.sult_val').disabled = true;
              document.getElementById('fspl_result_val').disabled = true;
              document.getElementById('sar_result_val').disabled = true;
                      // disables results fields by default
              function compute_skin_dpth(){
                var freq_range_optn,
                    cndctv_rstvty_optn,
                    freq_val,
                    condctvty_val,
                    resistivity_val,
                    skin_dpth,
                    freq_range_factor;
                        // vars dfn

                freq_val = document.getElementById('skin_dpth_freq_input_val').value;
                condctvty_val = document.getElementById('skin_dpth_cond_restvty_optn_val').value;
                resistivity_val = document.getElementById('skin_dpth_cond_restvty_optn_val').value;
                      // fetch set values

                var selected_cndctv_rstvty_optn = skin_dpth_form.elements['skin_dpth_cndvty_rsstvty_option'].selectedIndex;
                var selected_freq_range_optn = skin_dpth_form.elements['skin_dpth_freq_option'].selectedIndex;
                        // checks selected values
                if((selected_cndctv_rstvty_optn > 0) && (selected_freq_range_optn > 0)) {
                  if (freq_val <= 0) {
                      error_flag = 'ON'; //activated flg
                      alert("Frequency value is required!");
                  }
                  if (freq_val > 0) {
                        cndctv_rstvty_optn = skin_dpth_form.elements['skin_dpth_cndvty_rsstvty_option'].options[selected_cndctv_rstvty_optn].value;
                        freq_range_optn = skin_dpth_form.elements['skin_dpth_freq_option'].options[selected_freq_range_optn].value;
                              // get options by value
                      if(freq_range_optn ==="mhz"){
                          freq_val *= Math.pow(10,6);
                      }
                              // sets frequency factor to MHz range
                      if(freq_range_optn ==="ghz"){
                          freq_val *= Math.pow(10,9);
                      }
                              // sets frequency factor to GHz range
                  }
                  if(cndctv_rstvty_optn ==='conductivity') {
                      if (condctvty_val <= 0) {
                          error_flag = 'ON'; //activated error flag
                          alert("Conductivity value is required!")
                      }
                      if (condctvty_val > 0 && error_flag === 'OFF') {
                          skin_dpth = Math.sqrt(1 / (pi * freq_val * uo * ur * condctvty_val));
                              // skin depth computation fn
                          var result = document.getElementById('skin_dpth_result_val');
                          result.value = skin_dpth.toFixed(6);
                              // sets result to 6 d.ps
                      }
                  }
                  if(cndctv_rstvty_optn ==='resistivity') {
                    resistivity_val *= Math.pow(10,-8);
                          // sets to [Ω.m]
                    if (resistivity_val <= 0) {
                        error_flag = 'ON'; //activated error flag
                        alert("Resistivity value is required!");
                    }
                    if (resistivity_val > 0 && error_flag === 'OFF') {
                        skin_dpth = Math.sqrt(resistivity_val / (pi * freq_val * uo * ur));
                            // skin depth computation fn
                        var result = document.getElementById('skin_dpth_result_val');
                        result.value = skin_dpth.toFixed(6);
                            // sets result to 6 d.ps
                    }
                  }
                }
                else {
                    alert("Conductivity / Resistivity option and frequency range are all required!")
                }
                        // ----------check conductivity/resistivity values--------
              }
                      // =======================SKIN DEPTH========================
              function compute_sar(){
                  var sar_efield_val,
                      sar_condctvty_val,
                      sar_mat_dnsty_val,
                      sar_result;

                  sar_efield_val = document.getElementById('sar_efield_input_val').value;
                  sar_condctvty_val = document.getElementById('sar_condctvty_input_val').value;
                  sar_mat_dnsty_val = document.getElementById('sar_mat_dnsty_input_val').value;
                        // fetch set values
                  if (sar_efield_val == 0) {
                      error_flag = 'ON'; //activated error flag
                      alert("E-field value is required!");
                  }
                  if (sar_condctvty_val == 0) {
                      error_flag = 'ON'; //activated error flag
                      alert("Conductivity value is required!");
                  }
                  if (sar_mat_dnsty_val == 0) {
                      error_flag = 'ON'; //activated error flag
                      alert("Material mass density value is required!");
                  }
                  if (error_flag === 'OFF') {
                      sar_result = (sar_condctvty_val * Math.pow(sar_efield_val,2)) / (2 * sar_mat_dnsty_val);
                          // computes SAR
                      var result = document.getElementById('sar_result_val');
                      result.value = sar_result.toFixed(8);
                          // sets result to 8 d.ps
                  }
              }
                      // =======================SAR========================
              function compute_fspl(){
                  var fspl_dist_val,
                      fspl_freq_val,
                      fspl_tx_gain_val,
                      fspl_rx_gain_val,
                      fspl_result,
                      fspl_dist_range_optn,
                      fspl_freq_range_optn;

                  fspl_dist_val = document.getElementById('fspl_dist_input_val').value;
                  fspl_freq_val = document.getElementById('fspl_freq_input_val').value;
                  fspl_tx_gain_val = document.getElementById('fspl_tx_gai_input_val').value;
                  fspl_rx_gain_val = document.getElementById('fspl_rx_gain_input_val').value;

                  var selected_fspl_dist_range_optn= fspl_form.elements['fspl_distance_range_option'].selectedIndex;
                  var selected_fspl_freq_range_optn = fspl_form.elements['fspl_freq_range_option'].selectedIndex;
                          // checks selected values
                  if ((selected_fspl_dist_range_optn > 0) && (selected_fspl_freq_range_optn > 0)) {
                      if (fspl_dist_val <= 0) {
                          error_flag = 'ON'; //activated error flag
                          alert('Distance value is required!');
                      }
                      if (fspl_dist_val > 0) {
                          fspl_dist_range_optn = fspl_form.elements['fspl_distance_range_option'].options[selected_fspl_dist_range_optn].value;
                          if (fspl_dist_range_optn === 'km') {
                              fspl_dist_val *= 1000;
                                // converts to meters
                          }
                          if (fspl_dist_range_optn === 'm') {
                              fspl_dist_val *= 1;
                                // maintain value in meters
                          }
                      }
                      if (fspl_freq_val <= 0) {
                          error_flag = 'ON'; //activated error flag
                          alert('Frequency value is required!');
                      }
                      if (fspl_freq_val > 0) {
                          fspl_freq_range_optn = fspl_form.elements['fspl_freq_range_option'].options[selected_fspl_freq_range_optn].value;
                                // get options by value
                           if (fspl_freq_range_optn === 'mhz') {
                              fspl_freq_val *= Math.pow(10,6);
                                // converts to Hz from MHz
                           }
                           if (fspl_freq_range_optn === 'ghz') {
                              fspl_freq_val *= Math.pow(10,9);
                                // converts to Hz from GHz
                           }
                      }
                      if (fspl_tx_gain_val <= 0) {
                          error_flag = 'ON'; //activated error flag
                          alert('Transmitter antenna gain value is required!');
                      }
                      if (fspl_rx_gain_val <= 0) {
                          error_flag = 'ON'; //activated error flag
                          alert('Reciever antenna gain value is required!');
                      }
                      if (error_flag === 'OFF') {
                          fspl_result = 20 * Math.log10(fspl_dist_val) +
                                        20 * Math.log10(fspl_freq_val) +
                                        20 * Math.log10((4*pi)/co) -
                                        fspl_tx_gain_val -
                                        fspl_rx_gain_val;
                                  // FSPL computation
                          var result = document.getElementById('fspl_result_val');
                          result.value = fspl_result.toFixed(4);
                              // sets result to 4 d.ps
                      }
                  }
                  else {
                    alert('Distance and frequency ranges are required!');
                  }

              }
                      // =======================FSPL========================
              function head_model_compute() {
                  var head_siz_val,
                      head_siz_optn_val,
                      skin_tsse_thcknss,
                      fat_tsse_thcknss,
                      bone_tsse_thcknss,
                      brain_tsse_thcknss;

                  var skin_sz_pcntg = 1.1111;
                  var fat_sz_pcntg = 1.5556;
                  var bone_sz_pcntg = 7.3333;
                  var brain_sz_pcntg = 90.00;
                        //model correlation properties
                        //REF(Codra L. Chand Handbook)
                  head_siz_val = document.getElementById('head_siz_model_input_val').value;
                  var selected_head_siz_model_option = head_siz_model_form.elements['head_siz_model_option'].selectedIndex;
                          // fetch values
                  if (selected_head_siz_model_option > 0) {
                      head_siz_optn_val = head_siz_model_form.elements['head_siz_model_option'].options[selected_head_siz_model_option].value;
                      if (head_siz_val > 0) {
                          var skin_thcknss_result = document.getElementById('head_siz_model_skin_thcknss_result_val');
                          var fat_thcknss_result = document.getElementById('head_siz_model_fat_thcknss_result_val');
                          var bone_thcknss_result = document.getElementById('head_siz_model_bone_thcknss_result_val');
                          var brain_thcknss_result = document.getElementById('head_siz_model_brain_thcknss_result_val');
                              //passing input fields id
                          var head_rds;

                          if (head_siz_optn_val ==='radius') {
                              head_rds = head_siz_val;
                          }
                          if (head_siz_optn_val ==="circumference") {
                              head_rds = head_siz_val / (2*pi);
                                  //head radius
                          }
                          if (error_flag === 'OFF') {
                              skin_tsse_thcknss = head_rds * (skin_sz_pcntg / 100);
                              fat_tsse_thcknss = head_rds * (fat_sz_pcntg / 100);
                              bone_tsse_thcknss = head_rds * (bone_sz_pcntg / 100);
                              brain_tsse_thcknss = head_rds * (brain_sz_pcntg / 100);
                                  //tissue thickness from head radius
                              skin_thcknss_result.value = skin_tsse_thcknss.toFixed(6);
                              fat_thcknss_result.value = fat_tsse_thcknss.toFixed(6);
                              bone_thcknss_result.value = bone_tsse_thcknss.toFixed(6);
                              brain_thcknss_result.value = brain_tsse_thcknss.toFixed(6);
                                  //sets results to 6d.plcs
                          }
                      }
                      else {
                          error_flag = 'ON'; //activated error flag
                          alert('Head size value is required!');
                      }
                  }else {
                    alert("Select head model size option[Radius/Circumference].");
                  }
              }
                      // =======================HEAD SIZE MODEL========================
              function sar_advanced_compute(){
                  var head_siz_val,
                      head_siz_optn_val,
                      dvc_distance_val,
                      dvc_distance_range_optn,
                      overal_distance,
                      transmitn_freq_val,
                      transmitn_freq_range_optn,
                      transmit_pwr,
                      antenna_gaiin,
                      rel_permeability_val,
                      rel_permitivity_val,
                      tissue_cndctvty_val,
                      tissue_dnsty_val,
                      efield_result_val,
                      pwr_dnsty_result_val,
                      impedance_result_val,
                      skin_dpth,
                      head_rds,
                      tissue_type_option,
                      sar_result_val;
                          //variables defined
                  var head_siz_val,
                      head_siz_optn_val,
                      skin_tsse_thcknss,
                      fat_tsse_thcknss,
                      bone_tsse_thcknss,
                      brain_tsse_thcknss;

                  var Pt_layer2,
                      Pt_layer3,
                      Pt_layer4;
                          // tissues powerfloat brn_pwr_attenuated;
                  var brn_pwr_attenuated,
                      brn_pwr_rcvd1,
                      brn_pwr_rcvd2;
                          //brain power
                  var skin_sz,
                      fat_sz,
                      bone_sz,
                      brain_sz;
                            //tissue size vars

                  var skin_sz_pcntg = 1.1111;
                  var fat_sz_pcntg = 1.5556;
                  var bone_sz_pcntg = 7.3333;
                  var brain_sz_pcntg = 90.00;
                        //model correlation properties
                        //REF(Codra L. Chand Handbook)

                    dvc_distance_val = document.getElementById('sar_advncd_dvc_dist_input_val').value;
                    var selected_dvc_distance_range_optn = sar_advanced_form.elements['sar_advncd_distance_range_option'].selectedIndex;
                    transmitn_freq_val = document.getElementById('sar_advncd_freq_input_val').value;
                    var selected_transmit_freq_range_optn = sar_advanced_form.elements['sar_advncd_freq_range_option'].selectedIndex;
                    head_siz_val = document.getElementById('sar_advncd_head_siz_input_val').value;
                    var selected_head_siz_model_option = sar_advanced_form.elements['sar_advncd_head_siz_option'].selectedIndex;

                    var selected_tissue_type_option = sar_advanced_form.elements['sar_advncd_tissue_type_option'].selectedIndex;

                    transmit_pwr = document.getElementById("sar_advncd_pwr_tr_val").value;
                    antenna_gaiin = document.getElementById("sar_advncd_ant_gain_val").value;
                    rel_permeability_val = document.getElementById("sar_advncd_rel_permeability_val").value;
                    rel_permitivity_val = document.getElementById("sar_advncd_rel_permitivity_val").value;
                    tissue_cndctvty_val = document.getElementById("sar_advncd_conductivity_val").value;
                    tissue_dnsty_val = document.getElementById("sar_advncd_tissue_dnsty_val").value;
                            // fetch values by id

                    if ((selected_head_siz_model_option > 0) &&
                        (selected_dvc_distance_range_optn > 0) &&
                        (selected_tissue_type_option > 0) &&
                        (selected_transmit_freq_range_optn > 0)){
                        head_siz_optn_val = sar_advanced_form.elements['sar_advncd_head_siz_option'].options[selected_head_siz_model_option].value;
                        dvc_distance_range_optn = sar_advanced_form.elements['sar_advncd_distance_range_option'].options[selected_dvc_distance_range_optn].value;
                        transmitn_freq_range_optn = sar_advanced_form.elements['sar_advncd_freq_range_option'].options[selected_transmit_freq_range_optn].value;
                        tissue_type_option = sar_advanced_form.elements['sar_advncd_tissue_type_option'].options[selected_tissue_type_option].value;
                        if (head_siz_val > 0) {
                            if (head_siz_optn_val ==='radius') {
                                head_rds = head_siz_val;
                            }
                            if (head_siz_optn_val ==="circumference") {
                                head_rds = head_siz_val / (2*pi);
                                    //head radius
                            }

                                    // -------tissues radius(from brain center)------
                            skin_sz = head_rds;
                                    //skin size dfn i.e 1.11 p.c of total head radius
                            fat_sz = (head_rds - ((skin_sz_pcntg / 100) * head_rds));
                                    //fat size dfn i.e 1.56 p.c of total head radius
                            bone_sz = (head_rds - (((skin_sz_pcntg + fat_sz_pcntg) / 100) * head_rds));
                                    //bone size dfn i.e 7.33 p.c of total head radius
                            brain_sz = (head_rds - (((skin_sz_pcntg + fat_sz_pcntg + bone_sz_pcntg) / 100) * head_rds));
                                    //brain size dfn i.e 90 p.c of total head radius

                            skin_tsse_thcknss = head_rds * (skin_sz_pcntg / 100);
                            fat_tsse_thcknss = head_rds * (fat_sz_pcntg / 100);
                            bone_tsse_thcknss = head_rds * (bone_sz_pcntg / 100);
                            brain_tsse_thcknss = head_rds * (brain_sz_pcntg / 100);
                                //tissue thickness from head radius
                        }
                        if ((head_siz_val <= 0) ||
                           (transmit_pwr <= 0) ||
                           (rel_permeability_val <= 0) ||
                           (rel_permitivity_val <= 0) ||
                           (tissue_cndctvty_val <= 0) ||
                           (tissue_dnsty_val <= 0) ||
                           (transmitn_freq_val <= 0) ||
                           (dvc_distance_val < 0)){
                            error_flag = 'ON'; //activated error flag
                            alert("Check all your values definition are required!");
                        }

                        if (transmitn_freq_val > 0) {
                                  // get options by value
                             if (transmitn_freq_range_optn === 'mhz') {
                                transmitn_freq_val *= Math.pow(10,6);
                                  // converts to Hz from MHz
                             }
                             if (transmitn_freq_range_optn === 'ghz') {
                                transmitn_freq_val *= Math.pow(10,9);
                                  // converts to Hz from GHz
                             }
                        }
                                  //frequency range conversion
                        if (dvc_distance_val > 0) {
                            if (dvc_distance_range_optn === 'cm') {
                                dvc_distance_val *= 0.01;
                                  //converts to meters from cm
                            }
                            if (dvc_distance_range_optn === 'm') {
                                dvc_distance_val *= 1;
                                  // maintains the value in meters
                            }
                            if (dvc_distance_range_optn === 'km') {
                                dvc_distance_val *= 1000;
                                  // converts to meters from km
                            }
                        }
                        if (antenna_gaiin <= 0) {
                            antenna_gaiin = 1;
                        }
                        if (error_flag === 'OFF') {
                            impedance_compute(rel_permeability_val, rel_permitivity_val);
                            skin_dpth_compute(transmitn_freq_val, tissue_cndctvty_val);
                            pwr_trsmtd(transmit_pwr, transmitn_freq_val, brain_sz, antenna_gaiin, dvc_distance_val, skin_dpth);
                            pwr_dnsty(transmit_pwr, antenna_gaiin);
                            compute_e_field(pwr_dnsty_result_val, impedance_result_val);
                            compute_advanced_sar(tissue_cndctvty_val, tissue_dnsty_val);
                        }
                    }
                    else {
                        error_flag = 'ON'; //activated error flag
                        alert("Check all your options definition are required.");
                    }

                    function impedance_compute(rel_u, rel_e){
                        impedance_result_val = no * Math.sqrt(rel_u / rel_e);
                        //tissue impedance computation
                        var result0 = document.getElementById("sar_advncd_impedance_result_val");
                        //pass result value by id
                        result0.value = impedance_result_val.toFixed(4);
                        //assigns value and set it to 6 d.plcs
                    }   //tissue impedance
                    function skin_dpth_compute(fc, tsse_condvty_val){
                        skin_dpth = Math.sqrt(1 / (pi*fc*uo*tsse_condvty_val));
                        overal_distance = dvc_distance_val + skin_dpth;
                        var result = document.getElementById("sar_advncd_skin_dpth_result_val");
                        //pass result value by id
                        result.value = skin_dpth.toFixed(4);
                        //assigns value and set it to 4 d.plcs
                    }   //tissue skin depth
                    function pwr_trsmtd(trans_pwr_val, fc, brn_sz, gn, da, dpth){
                        // alert(brn_sz);
                        var brain_sz = brn_sz;
                                //brain size;
                        var new_Pt;
                        Pt = trans_pwr_val;
                                // initial power value
                                // hold power received at the tissue
                        // var da = dvc_distance_val;
                        var pwr_dpth;
                        // var dpth = skin_dpth;

                        if(da > 0.0)
                        {
                            // alert("Power transmitted");
                            new_Pt = Pt * gn * Math.pow((co /(4*pi*fc*da)), 2);
                            Pt = new_Pt;
                                    // power transmitted from an antenna at a distance
                            pwr_dpth = dpth / 2;
                                    // power depth
                            // alert(Pt);
                        }
                        if(tissue_type_option === "Brain"){
                            if((da > 0))
                            {
                                Pt = Pt * 0.37;

                                if(dpth > brain_tsse_thcknss)
                                {
                                    Pt_layer4 = trans_pwr_val * Math.exp(dpth / brain_tsse_thcknss);
                                    Pt = Pt_layer4 - trans_pwr_val;
                                }
                                    // new Pt value id power depth is shorter than skin-thickness
                            }
                            brn_pwr_attenuated = 8.686 * (dpth / brain_sz);
                                //power attenuated at the brain in dB
                            brn_pwr_rcvd1 = ((Pt*1000)*.095916 )- brn_pwr_attenuated;
                                //power received at the brain in dBm
                                //'.095916'dBm = 1mW
                                //Math.pow(10,((dbm-30)/10))
                            brn_pwr_rcvd2 = Math.pow(10, ((brn_pwr_rcvd1-30)/10));
                                //power received at the brain in watts
                                //1W = 30dBm

                            if((dpth > bone_tsse_thcknss) && (tissue_type_option === "Brain") && (da === 0))
                            {
                                Pt_layer4 = Pt * Math.exp(dpth / brain_tsse_thcknss);
                                Pt = Pt_layer4 - trans_pwr_val;
                            }
                        }
                        else if((tissue_type_option === "Skin") || (tissue_type_option === "Fat") || (tissue_type_option === "Bone")){
                            if(da > 0.0)
                            {
                                if(dpth > skin_tsse_thcknss && tissue_type_option === "Fat")
                                {
                                    Pt_layer2 = Pt * Math.exp(skin_tsse_thcknss / dpth);
                                    Pt = Pt_layer2 - Pt;
                                }
                                if(dpth > fat_tsse_thcknss && tissue_type_option === "Bone")
                                {
                                    Pt_layer3 = Pt * Math.exp(fat_tsse_thcknss / dpth);
                                    Pt = Pt_layer3 - Pt;
                                }
                                else if(((dpth <= skin_tsse_thcknss) && (dpth <= fat_tsse_thcknss)) || tissue_type_option === "Skin")
                                {
                                    Pt = new_Pt;
                                }
                                        // power dfned after attenuation
                            }
                            else if(da === 0)
                            {
                                if(dpth > skin_tsse_thcknss && tissue_type_option === "Fat")
                                {
                                    Pt_layer2 = Pt * Math.exp(skin_tsse_thcknss / dpth);
                                    Pt = Pt_layer2 - trans_pwr_val;
                                }
                                if(dpth > fat_tsse_thcknss && tissue_type_option === "Bone")
                                {
                                    Pt_layer3 = Pt * Math.exp(fat_tsse_thcknss / dpth);
                                    Pt = Pt_layer3 - trans_pwr_val;
                                }
                                else if(((dpth <= skin_tsse_thcknss) && (dpth <= fat_tsse_thcknss) ) || tissue_type_option === "Skin")
                                {
                                    Pt = trans_pwr_val;
                                }
                                        // initial power value
                            }
                        }
                    }
                    function pwr_dnsty(Pwr_val, gn){
                        // alert("S density");
                        var result1 = document.getElementById("sar_advncd_pwr_dnsty_result_val");
                            //pass result value by id
                        Pt = Pwr_val;
                        if((tissue_type_option === "Skin") || (tissue_type_option === "Fat") || (tissue_type_option === "Bone")){
                            pwr_dnsty_result_val = (Pt*gn) / (4*pi*Math.pow(overal_distance,2));
                            //Power density computation
                            result1.value = pwr_dnsty_result_val.toFixed(4);
                            //assigns value and set it to 6 d.plcs
                        }
                        else if(tissue_type_option === "Brain"){
                            pwr_dnsty_result_val = (Pt*gn) / (4*pi*Math.pow(brain_sz,2));
                            //Power density computation
                            result1.value = pwr_dnsty_result_val.toFixed(4);
                            //assigns value and set it to 4 d.plcs
                        }
                    }
                    function compute_e_field(pwr_dnsty_val, impedance_val){
                        efield_result_val = Math.sqrt(pwr_dnsty_val * impedance_val);
                        //E field computation
                        var result2 = document.getElementById("sar_advncd_e_field_result_val");
                        //pass result value by id
                        result2.value = efield_result_val.toFixed(4);
                        //assigns value and set it to 4 d.plcs
                    }
                        // computes electric field intensity in V/m
                    function compute_advanced_sar(tsse_condvty_val, tsse_dnsty_val){
                        sar_result_val = (tsse_condvty_val * Math.pow(efield_result_val,2)) / (2*tsse_dnsty_val);
                        //computes SAR
                        var result3 = document.getElementById("sar_advncd_result_val");
                        //pass result value by id
                        result3.value = sar_result_val.toFixed(6);
                        //assigns value and set it to 6 d.plcs
                    }
                        // computes tissue SAR value
              }
                      // =======================SAR ADVANCED========================

            // ------------reseting action-------------
              function skin_dpth_fields_reset(){
                  document.getElementById('skin_dpth_form').reset();
                  document.getElementById('skin_dpth_re.sult_val').disabled = true;
                          // disables results fields by default
              }
                    // fn resets skin depth i/p fields
              function fspl_fields_reset(){
                  document.getElementById('fspl_form').reset();
                  document.getElementById('fspl_result_val').disabled = true;
                          // disables results fields by default
              }
                    // fn resets fspl i/p fields
              function sar_fields_reset(){
                  document.getElementById('sar_form').reset();
                  document.getElementById('sar_result_val').disabled = true;
                          // disables results fields by default
              }
                    // fn resets sar i/p fields
              function head_model_fields_reset(){
                  document.getElementById('head_siz_model_form').reset();
                  document.getElementById('head_siz_model_reset_button').disabled = true;
                          // disables results fields by default
              }
                    // fn resets sar i/p fields
              function sar_advanced_fields_reset(){
                  document.getElementById('sar_advanced_form').reset();
                  document.getElementById('sar_advanced_reset_button').disabled = true;
                          // disables results fields by default
              }
                    // fn resets sar i/p fields
            </script>
          </div>
        </div>
      </div>
    <!-- /#page-content-wrapper -->
  </div>
        <script>
					//navbar script handler
			$("#menu-toggle").click(function(e) {
			e.preventDefault();
			$("#wrapper").toggleClass("toggled");
			});
        </script>
    <!-- /#wrapper -->
  <!-- footer -->
  <?php
    include 'includes/footer.php'
  ?>
</body>

</html>

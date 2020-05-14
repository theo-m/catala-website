let url = "about";

type person = {
  name: string,
  website: option(string),
  affiliation: React.element,
};

let denis_merigoux = {
  name: "Denis Merigoux",
  website: Some("https://merigoux.fr"),
  affiliation:
    <Utils.TextLink target="https://prosecco.gforge.inria.fr">
      {"Inria Prosecco" |> React.string}
    </Utils.TextLink>,
};

let nicolas_chataing = {
  name: "Nicolas Chataing",
  website: Some("https://github.com/skodt"),
  affiliation:
    <Utils.TextLink
      target="https://www.ens.psl.eu/departement/departement-d-informatique">
      {{js|École Normale Supérieure|js} |> React.string}
    </Utils.TextLink>,
};

let sarah_lawsky = {
  name: "Sarah Lawsky",
  website:
    Some("http://www.law.northwestern.edu/faculty/profiles/SarahLawsky/"),
  affiliation:
    <Utils.TextLink target="www.law.northwestern.edu/">
      {{js|Northwestern Pritzker School of Law|js} |> React.string}
    </Utils.TextLink>,
};

let jonathan_protzenko = {
  name: "Jonathan Protzenko",
  website: Some("https://jonathan.protzenko.fr"),
  affiliation:
    <Utils.TextLink
      target="https://www.microsoft.com/en-us/research/group/research-software-engineering-rise/">
      {"Microsoft Research RiSE" |> React.string}
    </Utils.TextLink>,
};

let liane_huttner = {
  name: "Liane Huttner",
  website:
    Some(
      "https://www.pantheonsorbonne.fr/recherche/page-perso/page/?tx_oxcspagepersonnel_pi1[uid]=lhuttner",
    ),
  affiliation:
    <Utils.TextLink target="https://www.pantheonsorbonne.fr/accueil">
      {{js|Université Panthéon-Sorbonne|js} |> React.string}
    </Utils.TextLink>,
};

module Person = {
  [@react.component]
  let make = (~person: person) => {
    <li className=[%tw "pl-6 pb-4"]>
      {switch (person.website) {
       | None => person.name |> React.string
       | Some(website) =>
         <Utils.TextLink target=website>
           {person.name |> React.string}
         </Utils.TextLink>
       }}
      <span className=[%tw "pl-2"]>
        {"(" |> React.string}
        {person.affiliation}
        {")" |> React.string}
      </span>
    </li>;
  };
};

[@react.component]
let make = () => {
  <>
    <Utils.PageTitle>
      <Lang.String english="About" french={js|À propos|js} />
    </Utils.PageTitle>
    <Utils.PageSection
      title={
        <Lang.String
          english="Policy-maker oriented description"
          french={js|Résumé pour décideurs|js}
        />
      }>
      <p>
        <Lang.String
          english="In 2019, the French National Research Institute for Computer Science (Inria) has initiated an
      initiative focused on developing a new coding language for rules as code: Catala. The language is based on
      the field of formal methods, which are used in safety-critical domains like avionics or nuclear power
      plants to ensure that software behaves as expected, given a precise and unambiguous description of
      the expected behavior. Led by Denis Merigoux from the "
          french={js|En 2019, une initiative a été lancée au
        sein de l'Institut National de Recherche en Informatique et en Automatique afin de créer un nouveau
        langage de programmation pour transformer la loi en code  : Catala. Ce langage est issu du domaine
        des méthodes formelles, utilisées pour s'assurer que le logiciel se comporte comme prévu
        dans de nombreux secteurs où la sécurité est cruciale, comme l'aviation ou le nucléaire. Le projet
        est mené par Denis Merigoux de |js}
        />
        <Utils.TextLink target="https://prosecco.gforge.inria.fr/">
          <Lang.String
            english="Inria Prosecco group"
            french={js|l'équipe Prosecco d'Inria|js}
          />
        </Utils.TextLink>
        <Lang.String
          english={js| , in collaboration with academics from the Paris Panthéon-Sorbonne
       University and the Northwestern Pritzker School of Law, Catala is designed to achieve semantic
       equivalence with the law itself (its fundamental source of truth).|js}
          french={js|, en collaboration avec des universitaires de Paris Panthéon-Sorbonne et de la
           Northwestern Pritzker School of Law de Chicago. Le but du langage est d'atteindre une équivalence
           sémantique entre le code et la loi qui est sa source de vérité.|js}
        />
      </p>
      <p>
        <Lang.String
          english="Catala is unique because of its use of a style called literate programming, which sees each line of
        a legislative style text annotated with a snippet of code. This is of obvious benefit because it allows
        non-technical experts, such as policy makers and lawyers, to understand the representation of the code
        in relation to the legislation or rules. This allows Catala programmes to be easily verified and
        validated. Catala also comprises a compiler, which is a mechanism that allows for code to be
        translated into a range of programming languages, which improves interoperability. For example,
        the compiler can generate Javascript for web applications, SAS for economic models and COBOL for
        legacy environments. Crucially, the translated output will be guaranteed to behave in the same
        way as the original Catala programme. By using compilation, the code can be written once and be
        deployed everywhere; this avoids the need to manually write multiple versions of the code, which
        increases the chances of bugs. Catala remains an early stage project. In the future, the team is
        working on finalising the development of a compiler (e.g. for multiple languages including
        Javascript, Python, etc.) and implementing a large-size body of legislation to demonstrate the
        tool's utility."
          french={js|Catala est unique dans son domaine car il utilise une technique appelée programmation
            littéraire, où chaque ligne de texte législatif ou réglementaire est annoté par un petit morceau
            de code. Cela permet à des experts non-techniques comme des législateurs ou des juristes de
            comprendre localement la relation entre code et loi. De cette façon, les programmes Catala peuvent
            facilement être vérifiés et validés. De plus, un outil indispensable, le compilateur,
            traduit le code Catala vers divers langages de programmations plus traditionnels, rendant le
            système complètement interopérable. Par exemple, le compilateur peut générer du Javascript pour
            les applications web, du SAS pour les économistes et du COBOL pour les anciens ordinateurs centraux.
            Crucialement, le programme traduit par le compilateur est assuré de se comporter de la même manière
            que le programme Catala. En utilisant la compilation, le code peut être écrit une seule fois et
            déployé partout. Cela évite d'écrire manuellement plusieurs versions du même code et d'augmenter
            la probabilité de boggue. Catala n'en est cependant qu'à ses débuts ; les prochaines étapes
            pour le projet sont la finalisation du compilateur, ainsi que la transformation d'un gros morceau
            de législation en code afin de prouver l'utilié du langage.|js}
        />
      </p>
      <p className="float-right text-secondary pt-4 italic">
        <Lang.String
          english="Credit: the Catala team and James Mohun from the OECD Public Sector Innovation Observatory (2020)"
          french={js|Crédit : l'équipe de Catala ainsi que James Mohun, de l'observatoire de l'innovation dans le secteur public de l'OCDE (2020)|js}
        />
      </p>
    </Utils.PageSection>
    <Utils.PageSection
      title={<Lang.String english="People" french={js|Membres du projet|js} />}>
      <ul className=[%tw "list-none"]>
        <Person person=denis_merigoux />
        <Person person=liane_huttner />
        <Person person=nicolas_chataing />
        <Person person=jonathan_protzenko />
        <Person person=sarah_lawsky />
      </ul>
    </Utils.PageSection>
  </>;
};
